/**
 * Notice that the return value of the init function can be important in case of an error. That is, in case we
 * couldn't insert the module, we need to find out what's going on. Notice that we see that the exit function has 
 * no return value, unlike a userspace program! 
 * 
 * If we fail, we must return the negative of the value we like errno to be set! Note that errno 
 * resides in the VAS (virtual address space). Aside from using "man 3 errno.h", we can check inside 
 * include/uapi/asm-generic/(errno-base.h & errno.h) kernel source trees to see the table of values and messages. 
 * Hence for example, we may return -ENOMEM  to indicate lack of memory on allocation. The layer to which this 
 * message is returned is actually glibc, which has some glue code to multiply this value by -1 and then set the 
 * global errno. Now, the [f]init_module(2) system call will return -1, indicating failure (this is because 
 * insmod(8) actually invokes this system call. errno will be set to ENOMEM, reflecting the fact that the kernel 
 * module insertion failed due to a failure to allocate memory.
 * 
 * For example, consider the following kernel module, in which we allocate a kernel space pointer. If that allocation
 * fails, we thus return an error indicating that allocation and consequently module loading has failed.
 */

#include <linux/init.h>
#include <linux/slab.h>		// Header that has kmalloc and kfree.
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_AUTHOR("<insert your name here>");
MODULE_DESCRIPTION("LKP book:ch4/helloworld_lkm: hello, world, our first LKM");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

static int __init mem_alloc_module_init(void){
	void* ptr = kmalloc(87, GFP_KERNEL);

	if (!ptr){
		pr_warn("%s:%s:%d: kmalloc failed!\n", __FILE__, __func__, __LINE__);
		return -ENOMEM;
	}

	printk(KERN_INFO "Every thing went well in %s:%s:%d", __FILE__, __func__, __LINE__);
	return 0;
}

static void __exit mem_alloc_module_exit(void){
	printk(KERN_INFO "Module is exiting!");
}

module_init(mem_alloc_module_init);
module_exit(mem_alloc_module_exit);
