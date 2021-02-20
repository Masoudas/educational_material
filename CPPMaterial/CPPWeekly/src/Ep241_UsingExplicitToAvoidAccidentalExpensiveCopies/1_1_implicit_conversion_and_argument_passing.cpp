/**
* As we may recall, when we pass an argument to a function, if there's an implicit conversion from the type to the
* function argument, it will take place. As always, it will be useful to think about a function argument as a 
* normal variable.
*/
#include<string>

using namespace std;

void implicit_conversion(string s) {
	implicit_conversion("my string");	/* Note that my string is a const char*. When passing it inside the function,
										we say string s = "my string"; Here, an implicit constructor is called, changing
										const char* to string.*/
	implicit_conversion(s);	/* Again, note that string s = s; Here, a copy constructor is called implicitly.*/
}