/**
* Clearly, to implement polymorphism, the compiler must store some kind of type information in each object of 
* class Employee and use it to call the right version of the virtual function print(). In a typical implementation, 
* the space taken is just enough to hold a pointer.
* 
* The usual implementation technique is for the compiler to convert the name of a virtual function into an index 
* into a table of pointers to functions. That table is usually called the virtual function table or simply the
* vtbl. Each class with virtual functions has its own vtbl identifying its virtual functions.
* 
* This virtual call mechanism can be made almost as efficient as the "normal function call" mechanism (within
* 25%), so efficiency concerns should not deter anyone from using a virtual function where an ordinary function 
* call would be acceptably efficient. Its space overhead is one pointer in each object of a class with virtual 
* functions plus one vtbl for each such class. You pay this overhead only for objects of a class with a virtual 
* function.
* 
*/