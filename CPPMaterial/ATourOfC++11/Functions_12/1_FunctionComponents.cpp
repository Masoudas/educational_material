/**
 * As we already know, a function cannot be called unless it has already been declared.
 * 
 * A function's signature includes the function's name and the number, order and type of its formal parameters. 
 * Two overloaded functions must not have the same signature. The return value is not part of a function's signature
 * 
 * The semantics of argument passing are the same as copy assignment (Me: if this is a built-in type,
 * a copy constructor is called.) Moreover, implicit conversions take place when necessary.
 * 
 * A function has the following parts:
 * 1- Name, which is required.
 * 2- Argument list, which can be empty.
 * 3- A return type, which maybe void, or prefix or suffix (recall the famous decltyp() case for postfix return, in which case
 * an auto was used).
 * 4- inline: Indicating the function will be copied in place.
 * 5- constexpr: indicates the function can be computed at compile time if given constants as arguments.
 * 6- noexcept: Meaning that the function may not throw exceptions
 * 7- A linkage specification, for example static.
 * 8- [[noreturn]], meaning the function does not return using normal call/return style.
 * 
 * In addition, a member function (of a class) can be declared as:
 * 1- virtual: Indicating it can be overriden in a derived class.
 * 2- final: It may not be overriden in a derived class.
 * 3- override: It has overriden a virtual method.
 * 4- static: It is object independent.
 * 5- const: Indicating it may not modify the object.
 * 
 * And this is a treat from Bjarne himself:
 * struct S {
    [[noreturn]] virtual inline auto f(const unsigned long int ∗const) −> void const noexcept;
    };
 */

/**
 * In addition to normal function, we have some unorthodox functions as well, which are:
 * 1- Constructors: They don't return anything, and can't have their address taken.
 * 2- Destructors: Like constructors, and can't be overloaded.
 * 3- Function Objects: They're objects and can't be overloaded, but their operators are functions.
 * 4- Lambda expressions: These are a shorthand for defining function objects.
 */