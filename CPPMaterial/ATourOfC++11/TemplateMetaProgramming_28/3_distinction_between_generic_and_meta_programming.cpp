/**
* Where should we draw the line between meta and generic programming? The common idea is that:
*	-	It is all template metaprogramming: after all, any use of compile-time parameterization implies instantiation that 
*		generates "ordinary code."
*	-	It is all generic programming: after all, we are just defining and using generic types and algorithms
* 
* The big guys says "Both of these positions are useless because they basically define generic programming and template
* metaprogramming as synonyms. I think there is a useful distinction to be made. A distinction helps us decide between 
* alternative approaches to problems and to focus on what is important for a given problem. When I write a generic type 
* or algorithm, I don’t feel that I am writing a compile time program. I am not using my programming skills for the 
* compile-time part of my program. Instead, I am focusing on defining requirements on arguments. Generic 
* programming is primarily a design philosophy – a programming paradigm, if you must."
* 
* me: I think I understand what the big guy implies here. If we equate template metaprogramming and generic programming,
* we're conflating two things. For example, when I simply write a generic function, I'm not using any metaprogramming.
* But when I put conditions on the template parameter, I'm doing metaprogramming (I guess.) Hence, using concepts would
* be considered a form of metaprogramming.
* 
* He continues "In contrast, metaprogramming is programming. The emphasis is on computation, often involving selection 
* and some form of iteration. Metaprogramming is primarily a set of implementation techniques. I can think of four levels 
*	of implementation complexity:
*	[1] No computation (just pass type and value arguments)
*	[2] Simple computation (on types or values) not using compile-time tests or iteration, for example, && of Booleans 
*		or addition of units.
*	[3] Computation using explicit compile-time tests, for example, a compile-time if.
*	[4] Computation using compile-time iteration (in the form of recursion)"
* 
* The ordering indicates the level of complexity, with implications for the difficulty of the task, the difficulty of 
* debugging, and the likelihood of error.
*
* Question from me: Does specialization fall into metaprogramming or generic programming? I think it would fall into meta
* programming. This is because we're not changing the interface of the type (generic programming.) Rather we're manipulating
* the type (specialize it) to provide a more compatible interface for a type. Hence, metaprogramming.
* 
* Question: Is using concepts metaprogramming or generic programming? Again, we're not changing the interface of the 
* class or function. Rather, we're manipulating (setting conditions) on the type, which would fall in category IV. Hence,
* I'd say metaprogramming.
*/