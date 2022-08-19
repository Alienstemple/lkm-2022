#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("A B a@b");

int init_module(void)
{
	int d = 16;
        int m = 8;
        int y = 2022;
        printk(KERN_ALERT "Hello! Today is %d.%d.%d\n", d, m, y);
	return 0;
}
