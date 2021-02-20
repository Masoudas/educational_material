/**
* The process of generating a class or a function from a template plus a template argument list is
* often called template instantiation.
* 
* This is discussed in more detail in chapter 26. But apparently, a class definition is not generated as 
* long as it's not needed in C++. For example:

class X;	// No definition
X* x;	// It's fine. C++ can handle memory without knowing class definition.
X x;	// Now we need a class definition

* When it comes to templated classes or functions, once again, they're not generated until they're 
* absolutely necessary.

template<typename T>
class Link {
	Link* suc;  // OK: no definition of Link needed (yet)
				// ...
};

Link<int>* pl; // no instantiation of Link<int> needed (yet)
Link<int> lnk; // now we need to instantiate Link<int>

* A version of a template for a specific template argument list is called a specialization.
*/