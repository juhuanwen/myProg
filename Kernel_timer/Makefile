KERNEL_DIR = /home/samba/linux-2.6.32.2/
PWD = $(shell pwd)
all:
	make -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	rm -rf *.o *.ko
cp:
	cp drv_timer.ko /home/nfs
	
obj-m += drv_timer.o