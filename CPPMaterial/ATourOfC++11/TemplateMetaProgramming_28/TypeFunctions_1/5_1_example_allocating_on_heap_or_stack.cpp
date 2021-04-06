/**
* In what follows, we shall implement a type that would allocate on heap or stack, depending on whether or not the size of
* the requested object is smaller than a threshold (say size of an string). Essentially, we want something like this:
* 
* template<typename T>
* struct Obj_Holder{
*	using type = ...	# This would be something that allocates T one heap or stack.
* }
* 
* The above statement implies two things:
*	(1)	We need to check a condition in template arguments.
*	(2) We need to a mechanism to allocate on heap or stack.
* 
* Let's consider the second question first. If we want to allocate on heap, we'd just write 'new T' to allocate it's 
* type. The problem however is that this expression does not represent a type. Hence, we need to wrap this expression in
* something to make it a type. This could be even a function pointer. The problem however would be that we want to work
* with the type T, and access it with the dot operator, etc. Consequently, we define a type called On_Heap to take care
* of it.
* 
* For the types on stack, we can just return T. That way, Obj_Holder<int>::type would be int and no problem. The problem
* however would be that in this case, there would be no uniformity with On_Heap's interface. So, we define the following 
* uniform interface for the two types:
* 
* interface{
*		T& operator*();
*		T* operator->();
* }
* 
* This way, objects allocated on stack and on heap are accessed the same way. Looking at this interface, it acts as a
* pointer around the object we've created.
* 
* Note: The big guy does not define any constructor for these two objects, so they're default constructed, and then I
* can assign values to them. This does make sense, because we can access them by reference and assign to them then.
* 
* Ok! In the next file, we consider how to make the conditional statement. 
*/

template<typename T>
struct On_heap {
	On_heap() : t{ new T{} } { } // allocate
	~On_heap() { delete t; } // deallocate

	T& operator*() { return *t; }
	T* operator&() { return t; }

	On_heap(const On_heap&) = delete; // prevent copying
	On_heap operator=(const On_heap&) = delete;

private:
	T* t;
};

template<typename T>
struct Scoped {
	T& operator*() { return x; }
	T* operator->() { return &x; }

	Scoped(const Scoped&) = delete; // prevent copying
	Scoped operator=(const Scoped&) = delete;
private:
	T x; // the object
};
