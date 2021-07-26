/**
 * Below is our first kernel module. We shall break down our code as follows:
 * 
 * First, we add the header files corresponding to several of our kernel headers. Notice that these headers are in the
 * /usr/include/linux folder (could also be in /usr/include/$(uname -r)). The init header however seems to be kernel 
 * specific, and is found in the src folder, as we shall discuss below.
 * 
 * Note that if we list the include folder, we find a soft link called build, which points to the src folder corresponding
 * to the current kernel src folder, which is /usr/src/linux-headers-$(uname -r)/. We will supply this information to the 
 * Makefile used to build our kernel module. (Also, some systems have a similar soft link called source). Note that source
 * code is partially present here, as we don't require the entire linux source tree to build modules. The init.h header is
 * thus in this folder.
 * 
 * The MODULE_XXX macros are self evident. The modinfo command uses this information to print info about our module.
 * 
 * Next we have the concept of module entry and exit points. Because module code is not an executable, it does not have
 * a main method, or a return from main for that matter. That's why we provide the module_init and module_exit functions.
 * These are in fact macros for specifying such points. Notice that we provide two function names for these, one that
 * acts upon entry, and one upon exit. Think of these two as constructors and destructors of a module!
 * 
 * Notice the decorative values __init and exit for the init and exit functions of the module. These decorators don't
 * have any effect on the code, and are just illustrative, but useful. 
 * 
 * Making both functions static implies that these are private to this kernel module, and that's what we seek.
 *
 * The return value of the functions is also important. We see that the exit function has no return value, unlike a 
 * userspace program! If we fail, we must return the negative of the value we like errno to be set! Note that errno 
 * resides in the VAS (virtual address space). Aside from using "man 3 errno.h", we can check inside 
 * include/uapi/asm-generic/(errno-base.h & errno.h) kernel source trees to see the table of values and messages. Hence
 * for example, we may return -ENOMEM  to indicate lack of memory on allocation. The layer to which this message is
 * returned is actually glibc, which has some glue code to multiply this value by -1 and then set the global errno.
 * Now, the [f]init_module(2) system call will return -1, indicating failure (this is because insmod(8) actually invokes 
 * this system call. errno will be set to ENOMEM, reflecting the fact that the kernel module insertion failed due to a 
 * failure to allocate memory.
 * 
 * Finally, note that not inserting an exit functions the module will never be unloaded, unless after a reboot.
 * Of course, it's never that simple: this behavior preventing the unload is guaranteed only if the kernel is built with 
 * the CONFIG_MODULE_FORCE_UNLOAD flag set to Disabled (the default)
 * 
 * 
 */

// Suggested to be defined in other books.
#define MODULE
#define LINUX
#define __KERNEL__

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_AUTHOR("<insert your name here>");
MODULE_DESCRIPTION("LLKD book:ch4/helloworld_lkm: hello, world, our first LKM");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

static int __init helloworld_lkm_init(void)
{
	printk(KERN_INFO "Hello, world\n");
	return 0; /* success */
}

static void __exit helloworld_lkm_exit(void)
{
	printk(KERN_INFO "Goodbye, world\n");
}

module_init(helloworld_lkm_init);
module_exit(helloworld_lkm_exit);