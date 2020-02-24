KERNEL_DIR=/home/samba/linux-2.6.32.2/
PWD=$(shell pwd)
obj-m = drv_char.o
all:
	make -C $(KERNEL_DIR) M=$(PWD) modules
	arm-linux-gcc app_char.c -o app_char
clean:
	rm -rf *.o *.ko *.order *.mod.* Module.symvers
	rm -rf app_char
cp:
	cp drv_char.ko app_char /home/nfs