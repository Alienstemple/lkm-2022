#include "proc_demo.h"

int already_opened = 0;

DECLARE_WAIT_QUEUE_HEAD(WaitQ);

int node_open(struct inode *inode, struct file *file)
{
	int i, is_sig = 0;

	if (already_opened)
		if (file->f_flags & O_NONBLOCK) return -EAGAIN;
	
	try_module_get(THIS_MODULE);

	while (already_opened)
	{
		wait_event_interruptible(WaitQ, !already_opened);
		
		for (i = 0; i < _NSIG_WORDS && !is_sig; i++)
			is_sig = current->pending.signal.sig[i] & 
				~current->blocked.sig[i];

		if (is_sig)
		{
			module_put(THIS_MODULE);
			return -EINTR;
		}

		already_opened = 1;

		return 0;
	}

	return 0;
}

int node_close(struct inode *inode, struct file *file)
{
	already_opened = 0;

	wake_up(&WaitQ);
	module_put(THIS_MODULE);

	return 0;
}
