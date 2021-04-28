/**
* The big guy provides the following example, in which the alloc and free functions are used as virtual (non
* new or delete operators of course) to allocate resources of the class.
* 
* He also states that "There is no special syntax for placement of arrays. Nor need there be, since arbitrary 
* types can be allocated by placement new. However, an operator delete() can be defined for arrays." To which
* I say, Ok!
*/


class Arena {
public:
	virtual void* alloc(size_t)=0;
	virtual void free(void*)=0;
	// ...
};

void* operator new(size_t sz, Arena* a)
{
	return a->alloc(sz);
}

/*
// Allocation strategy
extern Arena* Persistent;
extern Arena* Shared;

void allocating_from_external_resources(int i)
{
	struct X {};
	X* p = new(Persistent) X; // X in persistent storage
	X* q = new(Shared) X; // X in shared memory
	// ...
}
*/