/**
 * Suppose that for an unGodly reason, we decided to return a non integer value from init. That is, we decided to
 * return a structure from it for example.
 * 
 * To do so, we can return an integer, which would actually be a memory address disguised as an int. In fact,
 * the ERR_PTR() inline function comes to our rescue, allowing us to return a pointer disguised as an integer 
 * simply by typecasting it as void*.
 * 
 * It actually gets better: you can check for an error using the IS_ERR() inline function (which really just 
 * figures out whether the value is in the range [-1 to -4095]), encodes a negative error value into a pointer 
 * via the ERR_PTR() inline function, and retrieves this value from the pointer using the converse routine 
 * PTR_ERR().
 * 
 * Note: What the above implies is this. A pointer must always have an strictly positive value. As such, if it
 * has a negative value, it means we have an error. Note that it's perfectly legal to assign a negative or zero
 * to a void pointer. However, what ERR_PTR does is that it casts a negative value into a void pointer for us.
 * Recall also that casting from void pointer to a pointer of type is implict. Therefore, myfunc uses this macro
 * to return either the pointer itself, or an error. In the init methid, we use the IS_ERR macro to check whether
 * the returned value is an error or not. If it is, we just print the corresponding error, and then use PTR_ERR
 * macro, we just convert our void pointer containing the negative value into an error. On the other hand, if
 * there's no error, then we can simply return the pointer value (conversion from pointer to integer only 
 * illicits a warning, and nothing more.)
 * 
 * Note that conversion from void* to any pointer is implicit in C, and not in C++.
 */

#include <linux/init.h>
#include <linux/slab.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/module.h>

struct mystruct{
};

struct mystruct * myfunc(void)
{

	struct mystruct *mys = NULL;
	mys = kzalloc(sizeof(struct mystruct), GFP_KERNEL);

	if (!mys)
		return ERR_PTR(-ENOMEM);

	return mys;
}

static int __init my_module_init(void){
	struct mystruct* gmys = NULL;
	gmys = myfunc();
	int stat = 0;

	if (IS_ERR(gmys)) {	// Did we return an error value?
		pr_warn("%s: myfunc alloc failed, aborting...\n", "OURMODNAME");
		stat = PTR_ERR(gmys); /* sets 'stat' to the value -ENOMEM */
		goto out_fail_1;
	}
	return stat; // I guess this must have been gmys!
	
	out_fail_1:
	return stat;
}