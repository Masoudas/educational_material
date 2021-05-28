/**
* Me: As we may recall, overrides of a function cannot throw more than the original function. Hence, if the 
* base function is noexcept, then overrides have to be as well. The same thing happens with pointer to functions
* too.
* 
*   -   A prvalue of type pointer to non-throwing function can be converted to a prvalue pointer to 
*       potentially-throwing function.
*   -   A prvalue of type pointer to non-throwing member function can be converted to a prvalue pointer to 
*       potentially-throwing member function.


void (*p)();
void (**pp)() noexcept = &p; // error: cannot convert to pointer to noexcept function

struct S
{
    typedef void (*p)();
    operator p();
};
void (*q)() noexcept = S(); // error: cannot convert to pointer to noexcept function

*/