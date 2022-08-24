#include "radio.h"

static char *array_msg[] = 
{
	"Zero radio dev speaking\n",
	"First radio dev speaking\n",
	"Second radio dev speaking\n"
};

ssize_t radio_read(struct file *file, char *buffer, size_t length, loff_t *offset)
{
	char *msg = 0;
	int msg_length = strlen(msg)+1;
	int ofs = *offset;
	char *p;
	ssize_t len;
	
	int minor = iminor(file->f_inode);
	printk(KERN_ALERT "Radio %d in use\n", minor);
	if (minor >= 3) return -EINVAL;  // Запретим использовать более 3 устройств

	msg = array_msg[minor];
	msg_length = strlen(msg) + 1;

	if (ofs >= msg_length) return 0;

	if (ofs + length > msg_length) length = msg_length-ofs;

	for (p = msg + ofs, len = length; len > 0; len--, p++, buffer++)
		put_user(*p, buffer);   //*buffer = *p;
	*offset += length;

	return length;
}






