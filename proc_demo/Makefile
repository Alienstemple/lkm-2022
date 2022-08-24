CURRENT = $(shell uname -r)
KERNEL_DIR = /lib/modules/$(CURRENT)/build
PWD = $(shell pwd)

obj-m := proc_demo.o

proc_demo-objs := proc_demo_main.o proc_demo_read.o proc_demo_write.o proc_demo_oc.o 

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
