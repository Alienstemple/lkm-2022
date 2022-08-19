#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("A B a@b");

void cleanup_module(void)
{
	printk(KERN_ALERT "Exit from hello\n");
}
