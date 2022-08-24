#include "radio.h"

#define BUF_SIZE 1024

static char r_buffer[BUF_SIZE];

ssize_t radio_write(struct file *file, const char *buffer, size_t length, loff_t *offset)
{
	int ofs = *offset;
	char *p;
	ssize_t len;

	printk(KERN_ALERT "Got string '%s' from radiowrite", buffer);

	if (ofs >= BUF_SIZE - 1) return 0;   /* 0 */

	if (ofs + length > BUF_SIZE - 1) length = BUF_SIZE-1-ofs;

	for (p = r_buffer + ofs, len = length; len > 0; len--, p++, buffer++)
		get_user(*p, buffer);   //*p = *buffer;
	*offset += length;

	return length;
}






