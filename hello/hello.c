#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("A B a@b");

static int __init hello_init(void)
{
	int d = 16;
        int m = 8;
        int y = 2022;
        printk(KERN_ALERT "Hello! Today is %d.%d.%d\n", d, m, y);
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_ALERT "Exit from hello\n");
}

module_init(hello_init);
module_exit(hello_exit);
