#include <linux/kernel.h>
#include <linux/module.h>
#include "my_alert.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Borisovskaya a@b");

int init_module(void)
{
	my_alert("Hello from kernel module \n");
	return 0;
}

void cleanup_module(void)
{
	my_alert("Goodbye\n");
}
