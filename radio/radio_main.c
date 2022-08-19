#include "radio.h"

static struct file_operations fops;
static int radio_major;
static int radio_count;

int init_module(void)
{
	/* init */
	memset(&fops, 0, sizeof(fops));
	fops.open = radio_open;
	fops.release = radio_release;
	fops.read = radio_read;
	fops.write = radio_write;

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

int radio_open(struct inode *inode, struct file *file)
{
	if (radio_count > 0) return -EBUSY;
	radio_count++;

	try_module_get(THIS_MODULE);
	printk(KERN_ALERT "'radio' in use, radio_count = %d\n", radio_count);
	return 0;
}

int radio_release(struct inode *inode, struct file *file)
{
	module_put(THIS_MODULE);
	radio_count--;
	return 0;
}













