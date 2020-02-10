KDIR = /opt/FriendlyARM/mini2440/linux-2.6.32.2/
PWD =$(shell pwd)
all:
	make -C $(KDIR) M=$(PWD) modules
	arm-linux-gcc mytest_app.c -o mytest_app
clean:
	rm -f *.swp *tmp* *.ko *.o *.mod.o *.mod.c *.symvers *cmd *.mod.o.cmd *.o.cmd
cp:
	cp mytest_drv.ko mytest_app /home/nfs
	
obj-m += mytest_drv.o
