/**
* Me: Form what I gather below, in the context below, even though we return a reference type that can be
* converted to the type we seek together with a non-reference type from two different functions, the compiler 
* gives precedence to the non-reference type, allowing us to convert the non-reference type to bool without 
* causing any double function error. 
* Of course, this is possible since C++14. Note that adding explicit however causes problem. Read the example 
* first, and then the following documentation:
* 
* In the following contexts, a context-specific type T is expected, [and the expression e of class type E is 
* only allowed if E has a single non-explicit user-defined conversion function to an allowable type (until 
* C++14)] {there is exactly one type T among the allowable types such that E has non-explicit conversion 
* functions whose return types are (possibly cv-qualified) T or reference to (possibly cv-qualified) T, and e 
* is implicitly convertible to T (since C++14).} Such expression e is said to be contextually implicitly 
* converted to the specified type T. Note that explicit conversion functions are not considered, even though 
* they are considered in contextual conversions to bool. (since C++11)
*	-	the argument of the delete-expression (T is any object pointer type);
*	-	integral constant expression, where a literal class is used (T is any integral or unscoped enumeration 
*		type, the selected user-defined conversion function must be constexpr);
*	-	the controlling expression of the switch statement (T is any integral or enumeration type)
* 
* Me: Note that the difference with the previous example is that here, we're not just talking about booleans.
* Had there been requirement for conversion to bool, even explicit conversions would be used!
* 
*/

#include <cassert>

template<typename T>
class zero_init
{
    T val;
public:
    zero_init() : val(static_cast<T>(0)) { }
    zero_init(T val) : val(val) { }
    operator T& () { return val; }  // Me: Setting an explicit here and below causes an error.
   // operator T() const { return val; }  // Note that removing this function means using the above function.
};

// The switch contexts require using int, and so does the i == 0 expression
void implicit_conversion()
{
    
    zero_init<int> i; //assert(i == 0);
    i = 7; assert(i == 7);
    switch (i) {}     // error until C++14 (more than one conversion function)
                      // OK since C++14 (both functions convert to the same type int)
    switch (i + 0) {} // always okay (implicit conversion)
}