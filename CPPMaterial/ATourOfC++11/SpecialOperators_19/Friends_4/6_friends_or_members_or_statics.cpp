/**
* Normally, when a function works on the members of the class (like += or ++), we better define it as a member function.
* However, it's a matter of taste how we want to define a member. For example, many people of not comfortable with saying
* mat m1 = m.inv(), but rather prefer mat m1 = inv(m), which implies that the latter should be defined a friend.
* 
* A method changing the state of a function should be a non-static non const member of the class. Do not change the state 
* of a class with friend fucntions, and if you do, you must take non-const references. binary operators are the most common 
* source of friend functions
* 
* Consider a class X below. Note that conversion are not applied to the leftmost operand of '.' and '->' operators, 
* otherwise 99.f1(x) would have worked! The global function f1() has a similar property because implicit conversions are 
* not used for nonconst reference arguments (§7.7). However, conversions may be applied to the arguments of f2() and f3():
*/

class X {
	// ...
	X(int);
	int m1(); // member
	int m2() const;
	friend int f1(X&); // friend, not member
	friend int f2(const X&);
	friend int f3(X);
};

void usage()
{
	// 99.m1(); // error : X(99).m1() not tried
	// 99.m2(); // error : X(99).m2() not tried
}

void more_usage()
{
//	f1(99); // error : f1(X(99)) not tried: non-const X& argument
//	f2(99); // OK: f2(X(99)); const X& argument, but f2 is not defined yet!
// 	f3(99); // OK: f3(X(99)); X argument, but f3 is not defined yet!
}