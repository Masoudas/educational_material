/**
* Note that when it comes to operator, ADL is done with more vigour let's say! This is because if we wanted
* to qualify operators with their names, then it would look horrible, and we'd lose the meaning altogether
* of using operators. In particular, if a class has an operator defined for it, naturally we use ADL to just
* use it, which I've been doing all the time, and this is nothing new, and the big guy mentions the difference
* between operators and normal functions too.
* 
*/

namespace ns {
	namespace ns1 {
		struct S{
			void operator+(S s){}
			static void g(S s){}
		};
	}

	void operator-(ns1::S, ns1::S) {};	// Notice the nested namespace data is not available to us (as always of course!)
}

void using_adl_on_nested_ns(ns::ns1::S s) {
	s + s;		// This is fine
	ns::ns1::S::g(s);		// This can't be without qualification.
	// g(s); Error!	Not for this one.
	// s - s; Not for the outer namespace no@
}
