/**
* The type checking provided for templates checks the use of arguments in the template definition rather than 
* against an explicit interface (in a template declaration) (Me: In other words, as opposed to a language like
* Java where we constrain a type to an interface, in C++ a type is checked for passing a couple of conditions,
* or a concept. A type can't be constraint to a particular interface in C++.)
* 
* This provides a compile-time variant of what is often called duck typing (If it walks like a duck and it quacks 
* like a duck, it’s a duck) (Me: I think, just think, that in Java we check that it's actually a duck (implements
* the interface, but in C++ we're content with if it behaves like a duck, not that it actually implements the
* interface.) Or – using more technical terminology – we operate on values, and the presence and meaning of an 
* operation depend solely on its operand values. This differs from the alternative view that objects have types, 
* which determine the presence and meaning of operations. Values "live" in objects. This is the way objects 
* (e.g., variables) work in C++, and only values that meet an object's requirements can be put into it. (Me: I 
* think this the reason why something like reinterpretation cast has meaning in C++. For example an int is an
* int, but we can look at it in a way to assume that it's a float. It walks like a duck and quacks like a duck.)
* What is done at compile time using templates does not involve objects, only values. In particular, there are no 
* variables at compile time. Thus, template programming resembles programming in dynamically-typed programming 
* languages, but the run-time cost is zero, and errors that in a run-time typed language manifest themselves as 
* exceptions become compile-time errors in C++ (Me: This is because languages like Python do work at runtime, but
* in C++, a generic program is compiled, and types are determined at compile time.) (Me: And this the reason why
* no guarantees are given to the type when writing program, and the templates are treated as if they have no type.
* We just know that they contain a value.)
* 
*/