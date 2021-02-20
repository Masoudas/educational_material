/**
* Typically an operator returns a result. Normally, we want to mess with the result, so returning a const
* is not a good idea.
* 
* We may return objects and use move semantics to fasciliate the returned object.
* 
* Note that operators that return one of their argument objects can – and usually do – return a reference.
* Like for example a matrix returns its ownself after addition with another matrix. This is particularly common 
* for operator functions that are implemented as members.
* 
* If a function simply passes an object to another function, an rvalue reference argument should be used.
* 
*/