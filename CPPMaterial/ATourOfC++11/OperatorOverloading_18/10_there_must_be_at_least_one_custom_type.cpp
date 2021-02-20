/**
* An operator function must either be a member or take at least one argument of a user-defined type
* (functions redefining the new and delete operators need not). This rule ensures that a user cannot
* change the meaning of an expression unless the expression contains an object of a user-defined
* type. In particular, it is not possible to define an operator function that operates exclusively on
* pointers. This ensures that C++ is extensible but not mutable (with the exception of operators =, &,
* and , for class objects).
* 
* An operator function intended to accept a built-in type as its first operand cannot be a member function.
* For example, consider adding a complex variable aa to the integer 2: aa+2 can, 
* with a suitably declared member function, be interpreted as aa.operator+(2), but 2+aa cannot because
* there is no class int for which to define + to mean 2.operator+(aa). Even if there were, two different
* member functions would be needed to cope with 2+aa and aa+2. Because the compiler does not
* know the meaning of a user-defined +, it cannot assume that the operator is commutative and so
* interpret 2+aa as aa+2. This example is trivially handled using one or more nonmember functions (or
* friend member functions).
*/

struct X{
	X(int){}
};
// X* operator+(X*, X*){} Error! Does not a have a custom type in it. A pointer is not a custom type!!!
						// Even though it points to a custom type, a memory address is just a memory address.
						// When did we ever dare to define operations on a pointer, saying how much to move
						// the pointer back and forth.
						// From another point of view, the operator does not have a custom type passed to it
						// as parameter, nor is it a member function.
