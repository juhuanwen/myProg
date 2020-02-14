#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/irq.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/gpio.h>
#include <mach/gpio.h>
#include <plat/gpio-cfg.h>
#include <linux/uaccess.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/poll.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/timer.h>        //内核定时器 

#define DEVICE_NAME "myPoll"

//生成一个等待队列头wait_queue_head_t,名字为myPoll_wait
static DECLARE_WAIT_QUEUE_HEAD(myPoll_wait);
static volatile int ev_press = 0;

static unsigned long * gpgconf=NULL;
static unsigned long * gpgdat=NULL;

struct timer_list timer;

static int dev_read(struct file *filp, char __user *buff, size_t count, loff_t *offp)
{
/* 	char buf[6]={'0','0','0','0','0','0'};
	//printk("1\n");
	if((*gpgdat&(0x1<<3))==0){
		msleep(10);
		if((*gpgdat&(0x1<<3))==0){
			//buf[1]='1';
			copy_to_user(buff,buf,6);
			//printk("2\n");
			//while((*gpgdat&(0x1<<3))==0);
		}
	} */
	return 0;
}

/* static int dev_read(struct file *filp, char __user *buff, size_t count, loff_t *offp)
{
	int err;
	unsigned char buf[8]={1,2,3,4,5,6,7,8};
	if(!ev_press){//ev_press==0时进入等待其他任务唤醒
		if(filp->f_flags&O_NONBLOCK){
			return -EAGAIN;
		}else{
			wait_event_interruptible(myPoll_wait, ev_press);
		}
	}
	ev_press=0;
	err=copy_to_user(buff,buf,8);
	return err;
} */
unsigned char gpg3_state=0;//按键状态防止连续发送poll信号
void timer_function(unsigned long data)
{
	mod_timer(&timer,jiffies+(2*HZ)/100);//更新定时器时间
	if((*gpgdat&(0x1<<3))==0){//判断是否有引脚按下
		if(gpg3_state==0){
			ev_press=1;//poll发送信号给应用，读数据吧
			wake_up_interruptible(&myPoll_wait);
			gpg3_state=1;
			//printk("gpg3_state=%d\n",gpg3_state);
		}
	}else{
		gpg3_state=0;
		ev_press=0;
	}
}

void mytimer_init(void )
{
	//初始化定时器
	init_timer(&timer);
	timer.data=0;
	timer.expires=jiffies+(2*HZ)/100;//20ms
	timer.function=timer_function;//到每20ms执行一次timer_function函数
	add_timer(&timer);
}

static int dev_open(struct inode *inode, struct file *file)
{
	gpgconf = ioremap(0x56000060,16);
	gpgdat = gpgconf+1;
	//GPG3置为输入
	*gpgconf &= ~(0x3<<6);
	*gpgconf |= (0x0<<6);
	mytimer_init();
	return 0;
}

static int dev_close(struct inode * inode, struct file *filp)
{
	iounmap(gpgconf);
	del_timer(&timer);
	printk(DEVICE_NAME "closed\n");
	return 0;
}

static ssize_t dev_write(struct file *file, const char __user * buffer, size_t count, loff_t *ppos)
{
	return 0;
}

static unsigned int dev_poll(struct file*file,struct poll_table_struct *wait)
{
	unsigned int mask = 0;
	poll_wait(file,&myPoll_wait,wait);
 	//printk("ev_press=%d\n",ev_press); 
	if(ev_press)//这个值为0时，直接退出等待队列，可由别的地方设置这个值为0，退出队列。正常是通过wake_up(myPoll_wait)唤醒
		mask |= POLLIN|POLLRDNORM;
	ev_press=0;
	return mask;
}

static struct file_operations dev_fops = {
    .owner   =   THIS_MODULE,
	.open	=	dev_open,
	.read	=	dev_read,
	.write	= 	dev_write,
	.release	=	dev_close,
	.poll	=	dev_poll,

};

static struct miscdevice misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEVICE_NAME,
	.fops = &dev_fops,
};

static int __init dev_init(void)
{
	int ret;
	ret = misc_register(&misc);
	printk (DEVICE_NAME"\tinitialized\n");
	return ret;
}

static void __exit dev_exit(void)
{
	misc_deregister(&misc);
	
}

module_init(dev_init);
module_exit(dev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("FriendlyARM Inc.");
