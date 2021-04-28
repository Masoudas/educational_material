/**
* In rare instances, do we need to call destructors, and the big guy says "A novice should think thrice before
* calling a destructor explicitly and also should ask a more experienced colleague before doing so."
* 
* For example. in 5_5_1, we had an external resource. Thus, in such an instance, we need to explicitly call the
* destructor:

void destroy(X* p, Arena* a)
{
	p->~X(); // call destructor (me: Nowhere did we specify calling the destructor of X)
	a->free(p); // free memory
}

* 
*/