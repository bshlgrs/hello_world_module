
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

static int __init proc_hello_init(void)
{
  printk("Hello World!\n");
  return 0;
}

module_init(proc_hello_init);
