#ifndef _PROCDEMO_H_
#define _PROCDEMO_H_

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>

#define NODE_NAME "proc_demo"
#define BUF_SIZE 1024

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Borisovskaya A a@a");

extern char response[BUF_SIZE];

ssize_t node_read(struct file*, char*, size_t, loff_t*);
ssize_t node_write(struct file*, const char*, size_t, loff_t*);
int node_open(struct inode*, struct file*);
int node_close(struct inode*, struct file*);

#endif /* _PROC_DEMO_H */
