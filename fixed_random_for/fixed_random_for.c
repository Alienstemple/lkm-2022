#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/random.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Borisovskaya A a@b");

static int m_count = 1;

/* Parameters settings */
module_param(m_count, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
MODULE_PARM_DESC(m_count, "my counter");
/***********************/

int init_module(void)
{
	long rand;
	int i;
	long j;

	printk(KERN_ALERT "For loop module started \n");
	if (m_count == 1) printk(KERN_ALERT "Default value for count was used\n");
	else printk(KERN_ALERT "Module's counter = %d\n", m_count);

	for (i = 0; i < m_count; i++) 
		printk(KERN_ALERT "Fixed index %d\n", i);

	get_random_bytes(&rand, sizeof(rand));
	rand = rand % 10;
	rand = abs(rand);
	printk(KERN_ALERT "Random number = %ld\n", rand);

	for (j = 0; j < rand; j++)
		printk(KERN_ALERT "Rand index %ld\n", j);

	return 0;
}

void cleanup_module(void)
{
	printk(KERN_ALERT "Command line parser module finished\n");
}
