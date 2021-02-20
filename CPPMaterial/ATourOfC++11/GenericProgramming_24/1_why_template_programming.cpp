/**
* The big guy says templates are for the following three purposes:
* 1- The ability to pass types (as well as values and templates) as arguments without loss of information. This 
*	 implies excellent opportunities for inlining, of which current implementations take great advantage.
* 2- Delayed type checking (done at instantiation time). This implies opportunities to weave together information 
*	 from different contexts.
* 3- The ability to pass constant values as arguments. This implies the ability to do compile-time computation.
* 
* The big guy mentions inlining, because as we know, templates have to be present in the translation unit being
* compiled directly. See Chapter 23, Source Code Organization.
* 
* In other words, templates provide a powerful mechanism for compile-time computation and type manipulation that 
* can lead to very compact and efficient code.
* 
* The first and most common use of templates is to support generic programming, that is, programming focused on 
* the design, implementation, and use of general algorithms. Here, "general" means that an algorithm can be 
* designed to accept a wide variety of types as long as they meet the algorithm’s requirements on its arguments.
* Templates provide (compile-time) parametric polymorphism.
* 
* There are many definitions of "generic programming." Thus, the term can be confusing. However, in the context of 
* C++, "generic programming" implies an emphasis on the design of general algorithms implemented using templates.
*/