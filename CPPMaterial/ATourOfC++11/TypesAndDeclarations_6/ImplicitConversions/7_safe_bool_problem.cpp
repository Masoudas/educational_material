/**
* Me: This part reminds us that in the contexts where bool is required (like in an if statement, for loops,
* predicates,) even explicit conversions to bool are used.
* 
* Until the introduction of explicit conversion functions in C++11, designing a class that should be usable in 
* boolean contexts (e.g. if(obj) { ... }) presented a problem: given a user-defined conversion function, such 
* as T::operator bool() const;, the implicit conversion sequence allowed one additional standard conversion 
* sequence after that function call, which means the resultant bool could be converted to int, allowing such 
* code as obj << 1; or int i = obj; (Me: The first one being shift left, not streaming)
*
* One early solution for this can be seen in std::basic_ios, which defines operator! and operator void*(
* until C++11), so that the code such as if(std::cin) {...} compiles because void* is convertible to bool, 
* but int n = std::cout; does not compile because void* is not convertible to int. This still allows nonsense 
* code such as delete std::cout; to compile, and many pre-C++11 third party libraries were designed with a 
* more elaborate solution, known as the Safe Bool idiom.
*/