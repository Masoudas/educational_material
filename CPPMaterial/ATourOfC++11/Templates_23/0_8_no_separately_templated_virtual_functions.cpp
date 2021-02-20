/**
* If you really think about it, it does make sense! However, I repeat here what is discussed in section 4 of
* this chapter.
* 
* WE CAN'T HAVE VIRTUAL (INDEPNDENTLY) TEMPLATED METHODS. It does make sense. Suppose we defined such a virtual
* function. Then how can a derived class know which version of the overriden method corresponds to the base
* virtual method. In particular, because the signature of the derived class may change from the base (for example
* derived one is instantiated with int, whereas the base one with double for example), then the virtual method may
* not even exist in the derived class! We could say that the compiler could just substitute the type in base class
* method, and generate it. But this goes into that two step rule we always talk about had. The compiler in this 
* case needs to first find the virtual function, then compare signatures to find the correct method, and if it does
* not exist, generate it. This is something C++ always avoids!
* 
* What about a function that is not templated, but uses the template type of the class? This time around, note that
* when the derived class is instantied, the base class of the same time is instantied too. So, this would be like
* a normal class, and the compiler can go look for the virtual method. So this is fine!
*/
#include <iostream>

template<typename T>
struct v_t_base {
	virtual void f(T t) { std::cout << "inside virtual template method of base\n"; };	// This is fine!

	//template<typename U>
	//virtual void f(U& t) {};	// This is not fine!
};

template<typename T>
struct v_t_derived : v_t_base<T> {
	void f(T t) override { std::cout << "inside virtual template method of derived\n"; };	// This is fine!
};

//int main() {
//	v_t_base<int>* base_ref = new v_t_derived<int>{};
//
//	base_ref->f(0);
//}