/*  内核定时器测试模块  */
#include <linux/kernel.h>        //内核 
#include <linux/module.h>        //内核模块 
#include <linux/init.h>            //模块初始化和注销 
#include <linux/slab.h>            //屋里内存分配管理 
#include <linux/list.h>         //内核链表 
#include <linux/timer.h>        //内核定时器 
#include <linux/delay.h>




struct timer_list timer;        //内核定时器

void timer_function(unsigned long para)
{
    printk("Timer Expired and para is:%ld\n",para);
 	timer.data += 1; 
	//msleep(20);//不能有延时
    mod_timer(&timer, jiffies+(5*HZ)/100);
	

} 

static int __init timer_init(void)
{
    init_timer(&timer);                //初始化内核定时器
    timer.data=10;                    //参数 
    timer.expires=jiffies+ (5*HZ)/100;    //延时20ms   
    timer.function=timer_function;    //定时器的执行函数
    add_timer(&timer);                //将定时器加入到系统定时器链表中
    printk("Create Timer Success!\n");
    return 0; 
}

static void __exit timer_exit(void)
{
    del_timer(&timer);                //删除该定时器 
    printk("Delete Timer!\n");
}

module_init(timer_init);
module_exit(timer_exit);

//内核模块声明
MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("EDISON REN"); 
MODULE_DESCRIPTION("KERNEL TIMER TEST"); 
MODULE_ALIAS("KERNEL TIMER TEST"); 
