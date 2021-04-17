/**
* When we write a template, we sometimes want to provide an operation for some template arguments, but not for others. For 
* example:

template<typename T>
class Smart_pointer {
	// ...
	T& operator*(); // return reference to whole object
	T* operator->(); // select a member (for classes only)
	// ...
}

* If T is a class, we should provide operator->(), but if T is a built-in type, we simply cannot do so (with the usual 
* semantics). Therefore, we want a language mechanism for saying, "If this type has this property, define the following."
* 
* Note from me: We can't use specialization here, because we can't specialize for built-in types (unless you want to write 
* every single one with cv by hand!)
* 
* We might try the obvious (me: wasn't obvious to me!):

template<typename T>
class Smart_pointer {
	// ...
	T& operator*(); // return reference to whole object
	if (Is_class<T>()) T* operator->(); // syntax error
	// ...
}

* However, that does not work. C++ does not provide an if that can select among definitions based on a general condition. 
* But, as with Conditional and Select (§28.3.1), there is a way. We can write a somewhat curious type function to make the 
* definition of operator->() conditional. The standard library (in <type_traits>) provides enable_if for that. The 
* Smart_pointer example becomes as implemented below.
* 
* If Enable_if's condition evaluates to true, its result is its second argument (here, T). If Enable_if's condition 
* evaluates to false, the whole function declaration of which it is part is completely ignored. In this case, if T is a 
* class, we get a definition of operator->() returning a T*, and if it is not, we don't declare anything.
* 
* You may consider Smart_pointer and operator->() exotic, but providing (defining) operations conditionally is very common. 
* The standard library provides many examples of conditional definition, such as Alloc::size_type and pair being movable 
* if both of their elements are. The language itself defines -> only for pointers to class objects.
* 
* In this case, the elaboration of the declaration of operator->() with Enable_if simply changes the kind of error we get 
* from examples, such as p->real():
*	-	If we unconditionally declare operator->(), we get a "-> used on a non-class pointer" error at instantiation time 
*		for the definition of Smart_pointer<double>::operator->() (me: point is that it's not left till runtime to catch
*		this error.)
*	-	If we conditionally declare operator->() using Enable_if, if we use -> on a smart_ptr<double>, we get a 
*		"Smart_ptr<double>::operator->() not defined" error at the point of use of Smart_ptr<double>::operator->().
* 
* In either case, we do not get an error unless we use -> on a smart_ptr<T> where T is not a class.
* 
* We have moved the error detection and reporting from the implementation of smart_pointer<T>::operator->() to its 
* declaration. Depending on the compiler and especially on how deep in a nest of template instantiations the error happens, 
* this can make a significant difference. In general, it is preferable to specify templates precisely so as to detect 
* errors early rather than relying on bad instantiations being caught. In this sense, we can see Enable_if as a variant of 
* the idea of a concept: it allows a more precise specification of the requirements of a template.
* 
* Note: For some unGodly reason, the double instantiation throws an error. This is a VS thing apparently, and it says 
* "Failed to specialize alias template" for p in the example below!!!
*/
#include <type_traits>
#include <complex>

template<typename T>
struct Smart_pointer {
	T& operator*() { return *t; }
	typename std::enable_if< std::is_class_v<T>, T*>::type operator->() { return t; }

	T* t;
};

/* Throws a weird VS related error saying couldn't work with double!!
void using_Smart_pointer(Smart_pointer<double> p, Smart_pointer<std::complex<double>> q)
{
	auto d0 = *p; // OK
	auto c0 = *q; // OK
	auto d1 = q->real(); // OK
	//auto d2 = p->real(); // error : p doesn’t point to a class object
	// ...
}*/

