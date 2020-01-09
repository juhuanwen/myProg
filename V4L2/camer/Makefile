all:
	#https://blog.csdn.net/dgy1223/article/details/80574546
	#指定头文件路径 指定库文件路径 链接到库文件
	arm-linux-gcc v4l2.c -o v4l2 -I /usr/local/arm/4.2.2-eabi/jpeg/include/ -L /usr/local/arm/4.2.2-eabi/jpeg/lib/ -ljpeg
	#需要将库文件保存到开发板根目录的/lib/下
	cp /usr/local/arm/4.2.2-eabi/jpeg/lib/libjpeg /home/nfs/LCDProj/libjpeg.so.9
	cp v4l2 /home/nfs/LCDProj
clean:
	rm -rf v4l2
cp:

	cp /home/nfs/LCDProj/out.bmp /media/sf_ubuntu16.04/sbc-2416/myProg/V4L2/camer/

