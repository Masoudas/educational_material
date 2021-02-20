/*
* A C++ class provides three constructors, two assignments, and destructor by default. We can override them, but we 
* shouldn't. The C++ iso standard indicates that:
* 
* 1-  If the programmer declares any constructor for a class, the default constructor is not generated for that class.
* 2-   If the programmer declares a copy operation, a move operation, or a destructor for a class, 
*	no copy operation, move operation, or destructor is generated for that class.
* 
* (Me: The second rule implies that by overriding any of the operations, we take ownership of the others.
* Hence, they're not generated by default).
*
* The second rule is not strongly enforced for different compilers. for backward compatibility, copy
* constructors and copy assignments are generated even if a destructor is defined. However, that generation 
* is deprecated in the ISO standard (�iso.D), and you should expect a modern compiler to warn against it.
*/