/**
* My motivation for looking in more depth in this issue was an example I came across in OpenCV. In that example,
* I tried to write a plus operator for the Mat class of OpenCV myself in the global namespace. So, something
* like

cv::Mat operator+(cv::Mat lhs, cv::Mat rhs);

* Then, as soon as I tried to use the function, I got an error saying compiler couldn't resolve the ambiguity
* between two overloads, which made me wonder why?
* 
* The answer as documented in the standard is this " Argument-dependent lookup, also known as ADL, or Koenig 
* lookup, is the set of rules for looking up the unqualified function names in function-call expressions, 
* including implicit function calls to overloaded operators. These function names are looked up in the 
* namespaces of their arguments IN ADDITION to the scopes and namespaces considered by the usual unqualified 
* name lookup." The stress is on in addition.
* 
* My initial idea was that the compiler would look in the immediate global namespace and then would stop right
* there, because it has found the operator. It would not do ADL. However, the above example illustrates that
* this is not the case. It would in addition do ADL. Therefore, I can't overload operators in my namespace.
* 
* I've also written another example below, where this is abundandtly clear that this rule does not apply only
* to operators, but to functions as well.
* 
* Of course, as always, qualifying the name with namespace solves the problem.
*/

namespace ns {
	struct S {};

	void use_ns(S s){}
}

namespace ns1 {
	void use_ns(ns::S s) {
//		use_ns(s);	// Error. One overload is here. In addition, another is found through ADL.
		ns1::use_ns(s);	// Fine
	}
}