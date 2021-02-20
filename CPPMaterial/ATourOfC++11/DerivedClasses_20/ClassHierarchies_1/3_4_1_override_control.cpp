/**
* As we're aware, it's possible to override a virtual method without using the override keyword. If you declare a 
* function in a derived class that has exactly the same name and type as a virtual function in a base class, then 
* the function in the derived class overrides the one in the base class.
* 
* That’s a simple and effective rule. However, for larger class hierarchies it can be difficult to be sure that 
* you actually override the function you meant to override. 
* 
* However, this approach is considered error-prone. Consider the following example. Now, without peeking the 
* solution, find three errors(ish) in the hierarchy! The errors were:
* -	B0::f() is not virtual, so you can’t override it, only hide it.
* - D::g() doesn’t have the same argument type as B0::g(), so if it overrides anything it’s not the virtual 
*	function B0::g(). Most likely, D::g() just hides B0::g()
* - There is no function called h() in B0, if D::h() overrides anything, it is not a function from B0. Most likely, 
*	it is introducing a brand-new virtual function.
* 
* Hence, for larger hierarchies more specific controls are useful:
* -	virtual: The function may be overridden.
* - =0: The function must be virtual and must be overridden.
* - override: The function is meant to override a virtual function in a base class
* - final: The function is not meant to be overridden
* 
* In the absence of any of these controls, a non-static member function is virtual if and only if it overrides a 
* virtual function in a base class.
*/

struct B0 {
	void f(int) const;
	virtual void g(double);
};

struct B1 : B0 { /* ... */ };
struct B2 : B1 { /* ... */ };
struct B3 : B2 { /* ... */ };
struct B4 : B3 { /* ... */ };
struct B5 : B4 { /* ... */ };

struct D : B5 {
	void f(int) const; // override f() in base class
	void g(int); // override g() in base class
	virtual int h(); // overr ide h() in base class
};

