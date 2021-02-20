/**
 * See https://docs.microsoft.com/en-us/cpp/cpp/constexpr-cpp?view=vs-2019#:~:text=The%20primary%20difference%20between%20const,All%20constexpr%20variables%20are%20const%20.
 * What's the difference between a const and a consexpr?
 * 
 * The primary difference is that initialization of const can be deferred until run-time, whereas
 * for constexpr it has to be done at compile time. 
 * 
 * When we say run-time, we literally mean object initialization inside constructor, which is why the following
 * initialization works, that allow us to have a constant class member.
 */
#include <iostream>
class A{
public:
    const int x;
    A(int x) : x(x){}
};

namespace Functions {
    void checking_the_function_() {
        A a{ 10 };

        std::cout << a.x;
    }

}

/**
 * As we already said in chapter 6, a constexpr can only hold literal types, hence it cannot hold pointers.
 * The only exception to pointers is the array of void or array of value types.
 */

/**
 * A variable can be declared with constexpr, when it has a literal type and is initialized.
 * If the initialization is performed by a constructor, the constructor must be declared as constexpr.

 * A reference may be declared as constexpr when both these conditions are met: 
 * The referenced object is initialized by a constant expression, and any implicit conversions invoked 
 * during initialization are also constant expressions. (Why would someone need to define a reference constexpr?)
 * 
 * So we can assign to a const using constexpr and vice-versa.
 * const int x = 10;
 * constexpr int y = x;
 * 
 * However, when it comes to assignment with function, we could only assign using constexpr to constant expression.
 * 
 */
