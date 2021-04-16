/**
* In general, look hard for ways to clean up the syntax presented to users without inventing a private language. Prefer 
* systematic techniques, such as specialization and the use of aliases, to macro hackery. Prefer constexpr functions to 
* templates for compile-time computation, and hide template metaprogramming implementation details in constexpr functions 
* whenever feasible. Alternatively, we can look at the fundamental complexity of what we are trying to do:
* 
*	[1]		Does it require explicit tests?
*	[2]		Does it require recursion?
*	[3]		Can we write concepts for our template arguments?
* 
* If the answer to question [1] or [2] is "yes" or the answer to question [3] is "no," we should consider whether there 
* may be maintenance problems. Maybe some form of encapsulation is possible? Remember that complexities of a template 
* implementation become visible to users ("leak out") whenever an instantiation fails. Also, many programmers do look 
* into header files where every detail of a metaprogram is immediately exposed.
* 
*/