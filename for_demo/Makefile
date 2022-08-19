CURRENT = $(shell uname -r)
KERNEL_DIR = /lib/modules/$(CURRENT)/build
PWD = $(shell pwd)

obj-m := hello.o fordemo.o

hello-objs := start.o stop.o

fordemo-objs := for_demo.o my_alert.o

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
