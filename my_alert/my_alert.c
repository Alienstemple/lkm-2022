#include <linux/kernel.h>
#include <linux/module.h>
#include "my_alert.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Borisovskaya A a@b");

int my_alert(char *msg)
{
	printk(KERN_ALERT "Message for my_alert is %s\n", msg);
	return 0;
}

EXPORT_SYMBOL(my_alert);
