#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Borisovskaya A a@b");

static int m_count = 1;
static char *m_char = "Empty";

/* Parameters settings */
module_param(m_count, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
MODULE_PARM_DESC(m_count, "my counter");

module_param(m_char, charp, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
MODULE_PARM_DESC(m_char, "my_string");
/***********************/

int init_module(void)
{
	printk(KERN_ALERT "Command line parser started \n");
	if (m_count == 1) printk(KERN_ALERT "Default value for count was used\n");
	else printk(KERN_ALERT "Module's counter = %d\n", m_count);
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_ALERT "Command line parser module finished\n");
}
