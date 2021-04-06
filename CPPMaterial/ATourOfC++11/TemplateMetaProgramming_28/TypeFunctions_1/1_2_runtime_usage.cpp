/**
* As we see with the is_polymorphic example, some type functions return values (boolean in this case) rather than types.
* As was the case with constexpr values, we can use these at runtime as well. Though, we mostly prefer to use these at
* compile time. Hence, for example we can say:
* 
* if constexpr (is_polymorphic<type>::value)	// Compile-time usage
* ...
* 
* if (is_polymorphic<type>::value)	// run-time usage
*/