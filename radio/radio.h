#ifndef _RADIO_H_
#define _RADIO_H_

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>

#define DEV_NAME "radio"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Borisovskaya A a@a");

int radio_open(struct inode*, struct file*);
int radio_release(struct inode*, struct file*);

ssize_t radio_read(struct file*, char*, size_t, loff_t*);
ssize_t radio_write(struct file*, const char*, size_t, loff_t*);

#endif /* _RADIO_H_ */
