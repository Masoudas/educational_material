/**
* A key aspect of generic programming, metaprogramming, and probably all uses of templates is the uniform handling 
* of built-in types and user-defined types. For example, an accumulate() operation does not care whether the types 
* of values it adds up are ints, complex<double>s, or Matrixes. What it cares about is that they can be added using 
* the + operator.
* 
* The use of a type as a template argument does not imply or require the use of a class hierarchy or any form of 
* run-time self-identification of the type of an object. This is logically pleasing and essential for 
* high-performance applications.
* 
*/