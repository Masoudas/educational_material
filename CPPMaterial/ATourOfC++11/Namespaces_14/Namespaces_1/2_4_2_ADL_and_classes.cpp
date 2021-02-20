/**
* When a class member invokes a named function, other members of the same class and its base
* classes are preferred over functions potentially found based on the argument types (operators 
* follow a different rule; §18.2.1, §18.2.5)
*/

namespace N {
	struct S { int i; };
	void f(S);
	void g(S);
	void h(int);
}

struct Base {
	void f(N::S);
};

struct D : Base {
	void g(N::S x)
	{
		f(x); // call Base::f()
		// h(1); // error : no h(int) available
	}
};
