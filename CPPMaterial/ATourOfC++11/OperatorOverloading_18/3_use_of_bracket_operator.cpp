/**
* The bracket operator is a bit special, in the sense that it cannot be overridden for a class. It's only
* use are limited to initialization and on the right-hand side of an expression. As such, we have the following:

void g(complex a, complex b)
{
a = {1,2}; // OK: right hand side of assignment
a += {1,2}; // OK: right hand side of assignment
b = a+{1,2}; // syntax error
b = a+complex{1,2}; // OK
g(a,{1,2}); // OK: a function argument is considered an initializer
{a,b} = {b,a}; // syntax error
}

* They wanted to return good error messages and catch errors, which is why bracket is limited in its use.
* 
*/
