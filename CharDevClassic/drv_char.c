#include <linux/fs.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/mm.h>
#include <linux/ioport.h>

#define CHR_NAME "mychar"
//#define CHR_MAJOR 200
#define CHR_COUNT	1

static int major=200;
static dev_t	dev_id;
static struct cdev mycdev;

static unsigned long *gpbconf=NULL;
static unsigned long *gpbdat=NULL;
/* static unsigned long *gpbup=NULL; */

static int mycdev_open(struct inode *inode, struct file *file)
{
	int retval;
	printk("dev/mychar is opened\n");

	if (!request_mem_region(0x56000010, 16, "gpb")) {
		printk("request_mem_region fail\n");
		retval = -EBUSY;
	}
	gpbconf=ioremap(0x56000010,16);
	if (gpbconf==NULL){
		retval = -EBUSY;
	}
	gpbdat=gpbconf+1;
	gpbup=gpbconf+2;
	*gpbconf&=~(0xFF<<10);
	*gpbconf|=(0x55<<10);
	*gpbdat&=~(0xF<<5);
/* 	*gpbup&=~(0xF<<5);//启用上啦
	*gpbup|=(0xF<<5);//关闭上啦 */
	//*gpbdat|=(0xF<<5);
	return 0;
}
static int mycdev_release(struct inode *inode, struct file *filp)
{
	
	*gpbdat|=(0xF<<5);
	iounmap(gpbconf);
	release_mem_region(0x56000010,16);
	return 0;
}

static const struct file_operations mychar_fops = {
	.owner	= THIS_MODULE,
/* 	.write	= cs5535_gpio_write,
	.read	= cs5535_gpio_read,*/
	.open	= mycdev_open,
	.release = mycdev_release,
};

static int __init CHR_init(void)
{
	int	retval;
	if (major) {
		dev_id = MKDEV(major, 0);
		retval = register_chrdev_region(dev_id, CHR_COUNT,
						CHR_NAME);
	}else {
		retval = alloc_chrdev_region(&dev_id, 0, CHR_COUNT,
					     CHR_NAME);
		major = MAJOR(dev_id);
	}
	if(retval<0){
		printk("chrdev_region fail\n");
	}else{
		printk("chrdev_region success,major=%d\n",major);
	}
	
	cdev_init(&mycdev,&mychar_fops);
	cdev_add(&mycdev,dev_id,CHR_COUNT);
	return 0;
	
}
static void __exit CHR_exit(void)
{

	cdev_del(&mycdev);
	unregister_chrdev_region(dev_id, CHR_COUNT);
}
module_init(CHR_init);
module_exit(CHR_exit);


MODULE_AUTHOR("Huanwen Ju <815468302@qq.com>");
MODULE_DESCRIPTION("S3c2440 GPIO Pin Driver Demo");
MODULE_LICENSE("GPL");