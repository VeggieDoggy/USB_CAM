export CROSS_COMPILE=
export ARCH=x86

KERN_DIR =  /usr/src/linux-headers-5.4.0-150-generic# 板子所用内核源码的目录

all:
	make -C $(KERN_DIR) M=`pwd` modules 
clean:
	make -C $(KERN_DIR) M=`pwd` modules clean
	rm -rf modules.order

# 参考内核源码drivers/char/ipmi/Makefile
# 要想把a.c, b.c编译成ab.ko, 可以这样指定:
# ab-y := a.o b.o
# obj-m += ab.o



obj-m += myuvc.o

