/**
* There are two main reasons for using metaprogramming techniques:
*	-	Improved type safety: We can compute the exact types needed for a data structure or algorithm so that we don’t 
*		need to directly manipulate low-level data structures (e.g., we can eliminate many uses of explicit type 
*		conversion).
*	-	Improved run-time performance: We can compute values at compile time and select functions to be called at run 
*		time. That way, we don’t need to do those computations at run time (e.g., we can resolve many examples of 
*		polymorphic behavior to direct function calls). In particular, by taking advantage of the type system, we can 
*		dramatically improve the opportunities for inlining. Also, by using compact data structures (possibly generated), 
*		we make better use of memory with positive effects on both the amount of data we can handle and the execution 
*		speed.
* 
* me: Regarding one, if we knew that for particular types, we can use built-in (value) types, then we can be less generic
* when writing a class template. For example, we could handle all built-in types with double, and then have a more generic
* case for custom types.
* 
* me: Regarding two: This one is fairly obvious, specially given that once again, for particular input arguments, we can
* choose particular functions, classes, etc. Note that this is not the same as overloading rules for example, which are
* done by the compiler alone. These are choices that we can make based on some logic the compiler may not understand.
* 
*/