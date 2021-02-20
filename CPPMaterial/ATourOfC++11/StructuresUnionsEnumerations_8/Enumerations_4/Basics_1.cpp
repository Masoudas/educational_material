/**
 * An enumeration is a type that can hold a set of integers. Enumeration values are called
 * enumerators.
 * 
 * A basic difference between enum class and a plain enum is that a plain enum can be implicitly
 * converted into an int, whereas as an enum class can't. It should be cast explicitly.
 * The other weird one is that a plain enum can be seen all throughout the scope!!!whereas an
 * enum class are local to the enums and variables.
 * 
 * The default initialization value for an enum (i.e, with a bracket) is always ZERO! 
 * whether 0 is actually part of the enum or not.
 * 
 * The default value of each enum is zero. (Me: Don't use enums for their integer values!)
 * 
 * In general, prefer enum classes!!!
 * 
 * An enum definition that has no values is called an unscoped enum (like enum A), whereas one with values
 * (like enum A {r1,r2}) is an scoped enum.
 */
#include <iostream>

using namespace std;
enum class A{ a=1, b};
enum B { c = 2, d };

void using_enum_basics()
{
    A x{};  // Set to zero, even though not part of enum!
        
    cout << static_cast<int>(x); // prints zero!.

    //cout << static_cast<int>(a); // This of course does not make sense!
    cout << d; // This however prints 3, because the the enum values are accessible throughout the scope.

}

//int main() {
//    using_enum_basics();
//}