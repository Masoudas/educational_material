/**
* As is the case with constructor, we can declare a conversion operator explicit, to avoid implict conversion to the type.
* As we already know, with implicit conversion, the expression is written on the right hand side of = equation. 
* (or function arguments for that matter). 
* 
* However, it is possible to declare a conversion operator explicit and have it apply only for direct initialization,
* where an equivalent explicit constructor would have been used.
* 
* For example, consider the standard library definition of uniqe_ptr. We can see that the conversion to bool is explicit!
* There's something odd to note here. Conversion to bool when checking inside an if statement is done, even though the 
* conversion to bool is explicit. Why? 
* Well, the standard says mentions four places where a value may be "contextually converted to bool". They fall into four 
* main groups:
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
*	- static_assert(t)
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
* In conclusion, particularly when it comes to conversion to bool, prefer using explicit conversion over implicit ones.
*/
#include <memory>
template <typename T, typename D = std::default_delete<T>>
class unique_ptr {
public:
	// ...
	explicit operator bool() const noexcept { return false; }; // does *this hold a pointer (that is not nullptr)?
	// ...
};

void using_unique_ptr(unique_ptr<int> p, unique_ptr<char> q, bool w) {
	if (p) { // This is fine, even though the converter operator is explicit.
		
	}

	// using_unique_ptr(p, q, q); Wrong, wrong, wrong, because implicit conversion takes place!

	// bool x = p; Error! converting pointer directly to bool.

	// int sum = p + q; Worse, had the conversion not been explicit, this summation would have been 2 or 1!!!
}
