/** Me:
* What is the difference between std::move and std::forawrd?
* 
* Perhaps the most important difference is that with forwarding, we can change the reference type (for example
* from a derived class to a base type), but this is impossible with move. 
* (Me: Over all, use of forwarding is more expressive, and declares intent, and explains what happens. Therefore,
* it's preferable over std::move).
* 
* Aside from that, when we pass a templated reference to a function, we can't distinguish whether it was
* lvalue or rvalue (see 5_2_3_cant_assing...). Hence, if we want to pass to another function (as lvalue or rvalue) 
* we need to have a function that preserves the reference type. We call this scheme perfect forwarding 
* (lvalue is forward as lvalue and rvalue as rvalue). 
* 
*/
#include <iostream>

using namespace std;

void overloaded(int const& arg) { std::cout << "by lvalue\n"; }
void overloaded(int&& arg) { std::cout << "by rvalue\n"; }

void overloaded_f(float const& arg) { }
void overloaded_f(float&& arg) {  }

template< typename t >
/* "t &&" with "t" being template param is special, and  adjusts "t" to be
   (for example) "int &" or non-ref "int" so std::forward knows what to do. */
void forwarding(t&& arg) {
    std::cout << "via std::forward: ";
    overloaded(std::forward< t >(arg));
    std::cout << "via std::move: ";
    overloaded(std::move(arg)); // conceptually this would invalidate arg
    std::cout << "by simple passing: ";
    overloaded(arg);

    overloaded_f(std::forward< float >(arg));   // Changing type is only possible with forward.
}

//int main() {
//    std::cout << "initial caller passes rvalue:\n";
//    forwarding(5);
//    std::cout << "initial caller passes lvalue:\n";
//    int x = 5;
//    forwarding(x);
//}