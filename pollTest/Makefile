KERNEL_DIR = /home/samba/linux-2.6.32.2/
PWD = $(shell pwd)
all:
	make -C $(KERNEL_DIR) M=$(PWD) modules
	arm-linux-gcc -o app_poll app_poll.c
clean:
	rm -f app_poll *.swp *tmp* *.ko *.o *.mod.o *.mod.c *.symvers *cmd *.mod.o.cmd *.o.cmd
cp:
	cp drv_poll.ko app_poll /home/nfs
	
obj-m += drv_poll.o
