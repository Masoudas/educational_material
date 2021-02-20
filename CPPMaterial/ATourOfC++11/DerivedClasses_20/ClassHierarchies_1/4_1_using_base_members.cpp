/**
* Functions do not overload across scopes, they only hide one another. Dragging the functions of other name
* spaces require dragging them inside with the 'using' expression. 
* 
* As we already know, introducing a function with the same name as the parent scope hides the parent class. This
* is clearly illustrated with the following example. Pay special attention to this example. Note that when we use
* Base reference, all of a sudden, the version of the method used is int, and not double! The best way to make 
* sense of this bizzare phenomenon is to consider the name of a class the same as scoping to a name space. So
* if base and derived were namespaces here, then we'd know that saying base::f() would call the base class method.
* In much the same manner, saying br.f() here does the same job! So, beware of this phenomenon!
* 
* As for namespaces, using-declarations can be used to add a function to a scope.
* 
* Note that we can bring in a method from any location inside the hierarchy. Note also that access to the dragged
* method depends on the section of the class (public, private or protected) where it was declared.
* 
* We cannot use using-directives to bring all members of a base class into a derived class.
*/

struct Base {
	void f(int);
};

struct Derived : Base {
	void f(double);
};

void using_class_with_method_hiding(Derived d)
{
	d.f(1); // call Derived::f(double)
	Base& br = d;
	br.f(1); // call Base::f(int)

	// Same goes for the following
	Base* ptr = &d;
	ptr->f(1);	// Again, uses the integer version from the base namespace!

	Base b{ d };	// Slicing.
	b.f(1);	// Definitely the version from base!
}

struct Derive_And_Use : Base {
	using Base::f;	// Dragging the base class method here, just like a normal namespace.
	void f(double);
};

void using_class_with_dragged_method(Derived d)
{
	d.f(1); // Now calls Derived::f(int)
	Base& br = d;
	br.f(1); // call Base::f(int)
}