/**
* Imagine the following example. We say that A is a type, that has an alias called U. Now, notice that we define an
* alias B for this parameter U, but then use this same alias to define U, which is very weird and totaly cyclic, and
* totally not allowed in C++, and by any rational person.
* 
* As we can see, this is more of a logical error than a fault of aliasing.
*/ 

template<class T>
struct A;

template<class T>
using B = typename A<T>::U; // type-id is A<T>::U

template<class T>
struct A {
	typedef B<T> U;	// Error! Defining U as a templated alias for U!
};