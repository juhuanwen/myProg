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


static unsigned long *gpgconf=NULL;
static unsigned long *gpgdat=NULL;

unsigned int ev_press=0;
//注册一个等待队列button_waitq
static DECLARE_WAIT_QUEUE_HEAD(button_waitq);

//中断函数
static irqreturn_t gpio_test_K2irq(int irq, void *dev_id)
{
/* 	int ret;
	//申请引脚
	ret = gpio_request(S3C2410_GPG(3), "K2");//ENT11
	if (ret < 0) {
		pr_err("%s: failed to get GPG3\n", __func__);
		return ret;
	}
	//设为输入
	gpio_direction_input(S3C2410_GPG(3));
	if (gpio_get_value(S3C2410_GPG(3) == 0)) {
		printk("1\n");
	} else {
		printk("2\n");
	}
	//释放引脚
	gpio_free(S3C2410_GPG(3)); */
	/* //配置GPG3为外部中断11
	*gpgconf&=(0xffff&(0x2<<6));
	*gpgconf|=0x2<<6; */
	if (gpio_get_value(S3C2410_GPG(3)) == 0) {
		printk("1\n");
	} else {
		printk("2\n");
	}
	//，告诉人家wait_event_interruptible中断发生了
	wake_up_interruptible(&button_waitq);
	ev_press=1;//跳出等待
	return IRQ_RETVAL(IRQ_HANDLED);
}


static ssize_t gpio_test_write(struct file *file, const char __user *data,size_t len, loff_t *ppos)
{
	u8 buf[8];
	int res;
	if (copy_from_user(buf, data, 8)) {
			res = -EFAULT;
	}
	printk("gpio_test_write\n");
	return 0;
}

ssize_t gpio_test_read(struct file *filp, char __user *buf, size_t size, loff_t *ppos)
{
	u8 buf1[8]={0x01,0x02,0x03,0x04,0x05,0x07,0x07,0x08};
	int res;
	if (filp->f_flags & O_NONBLOCK)
	    return -EAGAIN;
	else
	    wait_event_interruptible(button_waitq, ev_press);

	//buf1[0]=gpio_get_value(S3C2410_GPG(3));
	if (copy_to_user(buf, buf1, 8)) {
			res = -EFAULT;
	}
	ev_press=0;//再次进入等待
	printk("gpio_test_read\n");
	return 0;
}

static int gpio_test_open(struct inode *inode, struct file *file)
{
	int ret;
	printk("/dev/K2 open success\n");
	//配置GPG3为外部中断11
	*gpgconf&=~(0x3<<(2*3));
	*gpgconf|=(0x2<<(2*3)); 
	printk("gpgconf=%ld\n",*gpgconf);
	ret=request_irq(IRQ_EINT11, &gpio_test_K2irq, IRQ_TYPE_EDGE_FALLING, "K2_interrupt", NULL);
	if(ret){
		
		printk("%d request_irq error\n",__LINE__);
		disable_irq(IRQ_EINT11);
        free_irq(IRQ_EINT11, NULL);
	}
	return 0;
}

static int gpio_test_close(struct inode * inode, struct file * file)
{
	//配置GPG3为输入
	//*gpgconf&=(0xffff&(0x2<<6));
	//*gpgconf|=0x0<<6;
	free_irq(IRQ_EINT11,NULL);
	return 0;
}

static const struct file_operations gpio_test_k2_fops = {
	.owner = THIS_MODULE,
	.open = gpio_test_open,
	.read = gpio_test_read,
	.write	= gpio_test_write,
	.release = gpio_test_close,

};

static struct miscdevice misc={
	.minor=MISC_DYNAMIC_MINOR,
	.name="K2",
	.fops=&gpio_test_k2_fops,
};




static int __init gpio_test_init(void)
{

	
	//配置GPG3为外部中断11
	gpgconf = ioremap(0x56000060,16);
	//gpgdat = gpgconf+1;
	misc_register(&misc);
	return 0;
}




static void __exit gpio_test_exit(void)
{
	
	iounmap(gpgconf);
	misc_deregister(&misc);
}

module_init(gpio_test_init);
module_exit(gpio_test_exit);
MODULE_DESCRIPTION("MINI2440 S3c2440 K2 Driver");
MODULE_AUTHOR("Huanwen Ju");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:mini2440");
