/**
* As Bjarne concludes "Thus, a friend function should be explicitly declared in an enclosing scope or take an argument of
* its class or a class derived from that. If not, the friend cannot be called."
* 
* In other words, either we find the class through ADL, or it's in our circle of friends (this scope) or our parent's
* (parent scope). Otherwise, the friend cannot be found.
*/

// no f() in this scope

class X {
	friend void f(); // useless. Does not exist in this scope, parent, and can't be found through ADL.
	friend void h(const X&); // can be found through its argument
};

void g(const X& x)
{
//	f(); // no f() in scope. In other words, we can't find a 
	h(x); // X’s friend h(). Doesn't this happen due to ADL?
}

void h(const X&){}