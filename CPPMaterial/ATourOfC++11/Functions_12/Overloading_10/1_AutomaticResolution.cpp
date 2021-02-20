/**
* This is done by comparing the type of the given arguments with actual arguments, and then
* the version best matching them is called,  and give a compile-time error if no function is the best match
* 
* More precisely, the following order of criteria are applied:
* 1-	Exact match: All types exactly match the given types.
* 2-	Promotion:  That is, integral promotions (bool to int, char to int, short to int,
*	and their unsigned counterparts) and float to double. So no int to long, or double to long double.
* 3-	Conversion: int to double, double to int, long to long long, double to long double, Derived* to Base*,
* T* to void*, int to unsigned int.
* 4-	Match user defined conversions (like double to complex, c-style string to string).
* 5-	Math ellipsis argument.
* 
* If two matches are found at the highest level where a match is found, the call is rejected as ambiguous.
* Safety always comes first, which is why promotion takes precedence over conversion.
* 
* Function templates are handled by applying the overload resolution rules to the result of specialization 
* based on a set of arguments. There are separate rules for overloading when a
* {}-list is used (initializer lists take priority) and for rvalue reference template
* arguments.
* 
* Note that return type is not part of function signature. Also, overload only occurs in one scope.
* 
* Remember the golden rule by the effective Java guy: Don't overload with same number of parameters. Don't
* overload with types having a common parent.
*
*/

void function_overloaded_with_float(int x){}
void function_overloaded_with_float(float x) {
	// function_overloaded_with_double({}); Ambiguous call
	// function_overloaded_with_float(1.1); Ambiguous, which one should be called? 
	function_overloaded_with_float(1.1f);	// ok
	
}

void print(int) {};
void print(const char*) {};
void print(double) {};
void print(long) {};
void print(char) {};
void checking_overload_resolution(char c, int i, short s, float f)
{
	print(c); // exact match: invoke print(char)
	print(i); // exact match: invoke print(int)
	print(s); // integral promotion: invoke print(int)
	print(f); // float to double promotion: print(double)
	print('a'); // exact match: invoke print(char)
	print(49); // exact match: invoke print(int)
	print(0); // exact match: invoke print(int)
	print("a"); // exact match: invoke print(const char*)
	print(nullptr); // nullptr_t to const char* promotion: invoke print(cost char*)
}

