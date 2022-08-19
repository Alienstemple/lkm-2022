#include "radio.h"

static struct file_operations fops;
static int radio_major;

int init_module(void)
{
	/* init */
	memset(&fops, 0, sizeof(fops));
	/* register radio dev */
	radio_major = register_chrdev(0, DEV_NAME, &fops);

	if (radio_major < 0)
	{
		printk(KERN_ALERT "Cannot register 'radio' device \n");
		return radio_major;
	}	

	printk(KERN_ALERT "'radio' module and device are running. Major number = %d \n", radio_major);
	return 0;
}

void cleanup_module(void)
{
	unregister_chrdev(radio_major, DEV_NAME);
	printk(KERN_ALERT "'radio' unregistered\n");
}
