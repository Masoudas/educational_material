/**
* The standard immediately continues to talk about the rules associated with how ADL takes place. What's of
* importance in these rules is that all the namespaces the class is nested in will be searched. Hence, if
* it's a class, we start from the class namespace and then its namespace. Note the difference between 
* operator and function however.
* 
* We don't however go to the enclosing namespaces. Hence, namespaces are considered only one level! 
*/

namespace _ns {
	namespace _ns1 {
		struct S{
			void operator+(S s){}
			static void g(S s){}
		};
	}

	void f(_ns1::S) {};	// Notice the nested namespace data is not available to us (as always of course!)
}

void _using_adl_on_nested_ns(_ns::_ns1::S s) {
	s + s;		// This is fine
	_ns::_ns1::S::g(s);		// This can't be without qualification.
	// g(s); Error!
	_ns::f(s);	// Error without qualifying with ns
}