/**
* What if a function uses parameters from several namespaces?
* 
* In such cases, we look for the function in the scope of the call (as ever) and in the namespaces of
* every argument (including each argument’s class and base classes) and do the usual overload resolution 
* of all functions we find. In particular, for the call d==s, we look for operator== in the 
* scope surrounding f(), in the std namespace (where == is defined for string), and in the Chrono 
* namespace. There is a std::operator==(), but it doesn’t take a Date argument, so we use 
* Chrono::operator==() that does.
* 
* God above!
*/

#include <string>

namespace Chrono {
	class Date {};
	bool operator==(const Date&, const std::string&) { return false; }
	std::string format(const Date&) { return ""; };
}

void f(Chrono::Date d, std::string s)
{
	if (d == s) {
		// ...
		format(d);
	}
	else if (d == "August 4, 1914") {
		// ...
	}
}