KERNEL_DIR=/home/samba/linux-2.6.39.3/
PWD=$(shell pwd)
all:
	make -C $(KERNEL_DIR) M=$(PWD) modules
	arm-linux-gcc main.c -o main
clean:
	rm main
cp :
	cp main /home/nfs/
	