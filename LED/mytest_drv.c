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

#define DEVICE_NAME "myLed"

//typedef unsigned int	   u32;

unsigned long *gpbconf=NULL;
unsigned long *gpbdat=NULL;

static struct file_operations dev_fops = {
    .owner   =   THIS_MODULE,

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
	gpbconf=ioremap(0x56000010,16);
	gpbdat=gpbconf+1;
	*gpbconf&=~(0xFF<<(2*5));
	*gpbconf|=(0x55<<(2*5));
	
	*gpbdat&=~(0xF<<5);
	*gpbdat|=(0xF<<5);
	printk (DEVICE_NAME"\tinitialized\n");
	printk("*gpbconf=%ld\n",*gpbconf);
	printk("*gpbdat=%ld\n",*gpbdat);
	return ret;
}

static void __exit dev_exit(void)
{
	iounmap(gpbconf);
	misc_deregister(&misc);
}

module_init(dev_init);
module_exit(dev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("FriendlyARM Inc.");
