#include "proc_demo.h"

ssize_t node_read(struct file *file, char *buffer, size_t length, loff_t *offset)
{
	int len = strlen(response)+1;
	loff_t ofs = *offset;

	int i;

	if (ofs >= len) return 0;

	if (ofs+length > len) length = len - ofs;

	for (i = ofs; i < len; i++)
		buffer[i] = (response+ofs)[i];

	*offset += length;

	return length;
}
