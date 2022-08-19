#include <linux/kernel.h>
#include <linux/module.h>
#include "my_alert.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Borisovskaya A a@b");

int my_alert(char *msg)
{
	int i;
	printk(KERN_ALERT "Message for my_alert is %s\n", msg);
	for (i = 0; i < 10; i++)
		printk(KERN_ALERT "Index = %d \n", i);
	return 0;
}

EXPORT_SYMBOL(my_alert);
