/**
* Argument-dependent lookup, also known as ADL, or Koenig lookup, is the set of rules for looking up the 
* unqualified function names in function-call expressions, including implicit function calls to overloaded 
* operators. These function names are looked up in the namespaces of their arguments in addition to the scopes 
* and namespaces considered by the usual unqualified name lookup.
*
* Argument-dependent lookup makes it possible to use operators defined in a different namespace. Example is
* given below:
* 
* Notes:
* Because of argument-dependent lookup, non-member functions and non-member operators defined in the same 
* namespace as a class are considered part of the public interface of that class (if they are found through 
* ADL). ADL is the reason behind the established idiom for swapping two objects in generic code:

using std::swap;
swap(obj1, obj2);

* because calling std::swap(obj1, obj2) directly would not consider the user-defined swap() functions that 
* could be defined in the same namespace as the types of obj1 or obj2, and just calling the unqualified 
* swap(obj1, obj2) would call nothing if no user-defined overload was provided. In particular, 
* std::iter_swap and all other standard library algorithms use this approach when dealing with Swappable 
* types. (me: I think the example wants to insist that we need the using declarative here, other unqualified
* swap does not call std::swap, naturlich.)
*/

#include <iostream>
void  adl_examples()
{
    std::cout << "Test\n"; // There is no operator<< in global namespace, but ADL
                           // examines std namespace because the left argument is in
                           // std and finds std::operator<<(std::ostream&, const char*)
    operator<<(std::cout, "Test\n"); // same, using function call notation
 
    // however,
//    std::cout << endl; // Error: 'endl' is not declared in this namespace.
                       // This is not a function call to endl(), so ADL does not apply
 
    endl(std::cout); // OK: this is a function call: ADL examines std namespace
                     // because the argument of endl is in std, and finds std::endl
 
//    (endl)(std::cout); // Error: 'endl' is not declared in this namespace.
                       // The sub-expression (endl) is not a function call expression
}

