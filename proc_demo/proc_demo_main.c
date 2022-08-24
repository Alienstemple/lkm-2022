#include "proc_demo.h"

static const struct proc_ops p_ops = 
{
	.proc_read = node_read,
	.proc_write = node_write,
	.proc_open = node_open,
	.proc_release = node_close
};

char response[BUF_SIZE] = "Default proc_demo response";

int init_module(void)
{
	struct proc_dir_entry *own_proc_node = 0;
	own_proc_node = proc_create(NODE_NAME, 0, NULL, &p_ops);

	if (!own_proc_node)
	{
		printk(KERN_ALERT "Cannot create /proc/%s\n", NODE_NAME);
		return -ENOMEM;
	}

	printk(KERN_ALERT "/proc/%s created\n", NODE_NAME);

	return 0;
}

void cleanup_module(void)
{
	remove_proc_entry(NODE_NAME, NULL);
	printk("Module finished, /proc/%s removed\n", NODE_NAME);
}



