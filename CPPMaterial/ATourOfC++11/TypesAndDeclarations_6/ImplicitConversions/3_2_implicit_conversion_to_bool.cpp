/**
* This is from another part of the standard:
* 
* In some contexts, regardless of whether or not a type a type is defined to have explicit or implicit 
* conversion to bool, it is converted to bool. 
* 
* In fact, the standard says there are four places where a value may be "contextually converted to bool". They fall into
* four main groups:
* 1- Statements
*	- if (t) 
*	- for (;t;)
*	- while (t) and do-while
* 
* 2- Expressions
*	- !t
*	- t && t2
*	- t || t2
*	- t ? "true" : "false"
* 
* 3- Compile-time tests
*	- static_assert(t);		// Me: Not run-time asserts! Pay attention!
*	- noexcept(t)
*	- if constexpr (t)
*	
* 4- Algorithms and concepts:
*	- NullablePointer T
*	- Anywhere the standard requires a type satisfying a concept.
*	- std::remove_if(first, last, [&](auto){ return t; });
*	- In any algorithm with a template parameter called Predicate or BinaryPredicate, the predicate argument can 
*	  return a T, like, std::sort(first, last, [&](auto){ return t; })
* 
* For example, a unique_ptr does not have an implict conversion to bool, it's explicit. However, we can say 
* if (uniqe_ptr(x)) because explicit version is used in this case. See Chapter 18, TypeConversion_3, 
* 6_explicit_type_conversion for a particular example of this.
*/