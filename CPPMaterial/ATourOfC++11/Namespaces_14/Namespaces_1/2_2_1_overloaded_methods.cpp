/**
* If there's an overloaded method, the using declarative brings all those methods in the scope.
* 
* (As a reminder, using can bring all overloads of base class constructor to the derived class, making it
* available for use).
*
* What if two methods have the exact same signature in the imported scope and this scope? As is the rule in
* C++, so long as we're not causing an error by trying to use the equivalent method, no problem occurs. As soon
* as we try to use the confliced error, we get a compile time error.
* 
* Using the same technique, we can bring base class methods into derived class.
*/

namespace ns {
	void f(int) {};
	void f(int, int) noexcept {};
}

namespace ns1 {
	void f(int, int, int) {}
	void f(int, int) {};
	using ns::f;

	void method_using_f() {
		f(1);
		//f(1, 2); //This is ambiguous, and a compile time error. Not caught by intellisense!
		f(1, 2, 3);
	}
}

struct base {
	void f() {};
};

struct derived : base {
	using base::f;

	void f(int) {	
		f();	// Both overloads of f are available now.
		f(5);
	}
};


void a_global_method() {};

namespace my_ns {
	using ::a_global_method;

	void a_global_method(int x) {
		a_global_method();
	}
}