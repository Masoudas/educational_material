/**
* The standard says:
* 
* The assert is a macro with the following definition:

#ifdef NDEBUG
#define assert(condition) ((void)0)
#else
#define assert(condition) implementation defined
#endif

* Note: Because assert is a macro, any commas in it would be interpreted as a comma to a macro, rather than
* one to the thing we seek. This especially happens with templates. The way to avoid this is with a extra
* paranthesis:

assert(std::is_same_v<int, int>); // error: assert does not take two arguments
assert((c == std::complex<double>{0, 0})); // OK

* Note from me: The first assertion works (at run-time) because true is replaced at compile time by the type 
* function, but then assertion code runs at run-time.
* 
* There is no standardized interface to add an additional message to assert errors. A portable way to include 
* one is to use a comma operator provided it has not been overloaded:
* assert(("There are five lights", 2 + 2 == 5));
* 
*/

// The example is from the standard:
#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

void c_assertion_examples()
{
    assert(2 + 2 == 4);
    std::cout << "Execution continues past the first assert\n";
    assertm(2 + 2 == 5, "There are five lights");
    std::cout << "Execution continues past the second assert\n";
    assert((2 * 2 == 4) && "Yet another way to add assert message");
}
