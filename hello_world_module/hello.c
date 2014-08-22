
/* hello world module - Eric McCreath 2005,2006,2008,2010,2012 */
// modified by Buck Shlegeris
/* to compile use:
    make -C  /usr/src/linux-headers-`uname -r` SUBDIRS=$PWD modules
   to install into the kernel use :
    insmod hello.ko
   to test :
    cat /proc/hello
   to remove :
    rmmod hello
*/

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>

static char *message = NULL;
struct mutex my_message_lock;

static int hello_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, message);
	return 0;
}

static int hello_proc_open(struct inode *inode, struct file *file)
{

	return single_open(file, hello_proc_show, NULL);
}

static ssize_t hello_proc_write(struct file *file, const char *buf,
  size_t count, loff_t *ppos)
{
  int amount_not_copied;

  mutex_lock(&my_message_lock);

  if(message) {
    kfree(message);
  }

  message = kmalloc(count + 1, 0);
  message[count] = 0;

  amount_not_copied = copy_from_user(message, buf, count);

  mutex_unlock(&my_message_lock);

  return count - amount_not_copied;
}

static const struct file_operations hello_proc_fops = {
	.open		= hello_proc_open,
	.read		= seq_read, // look at this kernel code
	.llseek		= seq_lseek,
	.release	= single_release,
  .write  = hello_proc_write
};

static int __init proc_hello_init(void)
{
  mutex_init(&my_message_lock);
  printk("init proc hello\n");
	proc_create("hello", 0666, NULL, &hello_proc_fops);
	return 0;
}
static void __exit cleanup_hello_module(void)
{
  remove_proc_entry("hello",NULL);

  printk("cleanup proc hello\n");
}


module_init(proc_hello_init);
module_exit(cleanup_hello_module);



