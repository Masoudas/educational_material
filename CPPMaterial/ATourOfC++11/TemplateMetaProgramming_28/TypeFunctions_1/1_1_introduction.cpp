/**
* A type function is a function that either takes at least one type argument or produces at least one type as a result. 
* For example, sizeof(T) is a built-in type function that given a type argument T returns the size of an object (measured 
* in chars)
* 
* Type functions don't have to look like conventional functions. In fact, most don’t. For example, the standard library’s 
* 'is_polymorphic<T>' takes its argument as a template argument and returns its result as a member called value:
*	-	if (is_polymorphic<int>::value) cout << "Big surprise!";
* Note that as such, type functions are defined with classes (rather than normal functions.)
* 
* me: Let's take a moment here and appreciate what was just uttered by the big guy. A normal function takes arguments
* using paranthesis, whereas type functions (a sort of meta function) uses brackets '<>' to get its arguments. Moreover,
* the return value maybe accessed using '::', or recently, they use 'using' as an alias to get the output of the type
* function as follows:
* using result = type_function<type>::type;		Convention is the return value of a type funtion is called type.
* 
* The standard-library convention is that a type function that returns a type does so by a member called type.
* Hence for example:

enum class Axis : char { x, y, z };
enum flags { off, x=1, y=x<<1, z=x<<2, t=x<<3 };

typename std::underlying_type<Axis>::type x; // x is a char
typename std::underlying_type<Axis>::type y; // y is probably an int

* Two points from this example from me:
*	-	underlying_type is an std function for returning the underlying type an enum
*	-	As we discuss in chapter 23, 0_10, the use of typename here is unnecessary, because the type is known at compile
*		time. 
*/
