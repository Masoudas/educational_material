/**
* Consider the following example, and note that we're not using namespace std. Then how come we are able to
* print the c-style and normal string, even though we've not declared them in the name space?

namespace std { 
	class string {};
	
	class ostream {
		// ...
		ostream& operator<<(const char∗); // output C-style string
	};
	
	extern ostream cout;
	ostream& operator<<(ostream&, const string&); // output std::string
} 

* The answer is that just like normal functions, we're looking for the operators in the namespace (see
* chapter 14_4. For example, with std::cout, we look for an operator inside the class that converts p
* to ostream. There's one. But there's none for string in the class. So we continue searching in the namespace,
* and voila, there's one. So, we in fact say operator<<(cout, string) and move forward from there.
* 
*/

#include <string>
#include <iostream>

void overload_resolution_of_operators()
{
	const char* p = "Hello";
	std::string s = "world";
	std::cout << p << ", " << s << "!\n";
}