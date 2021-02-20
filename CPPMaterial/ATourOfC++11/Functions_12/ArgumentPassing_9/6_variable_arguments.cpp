/**
* There are three ways to pass variable number of arguments to a function:
* 1-	Use initializer_list.
* 2-	Use a variadic template (§28.6): this allows us to handle an arbitrary number of arbitrary 
*	types in a type-safe manner by writing a small template metaprogram that interprets the
*	argument list to determine its meaning and take appropriate actions.
* 3-	Terminate the argument list with the ellipsis (...), which means ‘‘and maybe some more
*	arguments.’’ This allows us to handle an arbitrary number of (almost) arbitrary types by
*	using some macros from <cstdarg>. This solution is not inherently type-safe and can be
*	hard to use with sophisticated user-defined types. However, this mechanism has been
*	used from the earliest days of C.
* 
* A famous example of the third one is printf(const char* ... ). The ellipsis here indicated the
* parameters that replace % in the string: "%s %d", first is a c-string, second is a number.
* But the compiler cannot determine if the number of arguments are provided correctly, like
* std::printf("My name is %s %s\n",2);
* 
* A standard set of macros for accessing the unspecified arguments in such functions can be found in
* <cstdarg>.
* 
* Here's an example:
*/
#include <cstdarg>
#include <iostream>
using namespace std;

void error(int severity ...) // ‘‘severity’’ followed by a zero-ter minated list of char*s
{
	va_list ap;
	va_start(ap, severity); // arg startup
	for (;;) {
		char* p = va_arg(ap, char*);
		if (p == nullptr) break;
		cerr << p << ' ';
	}
	va_end(ap); // arg cleanup
	cerr << '\n';
	if (severity) exit(severity);
}