#include "proc_demo.h"

ssize_t node_write(struct file *file, const char *buffer, size_t length, loff_t *offset)
{
	loff_t ofs = *offset;
	int i;

	if (ofs+length >= BUF_SIZE-1)
		length = BUF_SIZE-1-ofs;

	for (i = ofs; i < length; i++)
		(response+ofs)[i] = buffer[i];

	*offset += length;

	return length;
}


