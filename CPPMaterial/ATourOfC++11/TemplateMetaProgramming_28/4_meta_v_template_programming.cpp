/**
* The big guy draws a distinction between template metaprogramming and metaprogramming:
*	-	metaprogramming: a metaprogram is a compile-time computation yielding types or functions to be used at run time.
*		Note that we don't say "template metaprogramming" because the computation may be done using constexpr functions.
* 
*	-	template metaprogramming: (from Wikipedia) Template metaprogramming (TMP) is a metaprogramming technique in which 
*		templates are used by a compiler to generate temporary source code, which is merged by the compiler with the rest 
*		of the source code and then compiled. The output of these templates include compile-time constants, data structures, 
*		and complete functions. The use of templates can be thought of as compile-time polymorphism
* 
* The examples are from me, but I hope they're correct. 
* 
* me: I guess metaprogramming is more generic than template meta-programming, and template metaprogramming is a sort of
* metaprogramming.
*/

// This is the sort of decision made at compile-time that does not involve templates
#include <type_traits>

// Note that no templates are involded here (sort of)
struct meta_programming {
	using int_32 = std::conditional<sizeof(int) == 4, int, long int>;
};

constexpr int instantiate_value_meta_programming() {
	if constexpr (true) {
		return 1;
	}
	else {
		return 0;
	}
}

// If enable_if fails, this class is not compiled! This is fortunate and necessary, because otherwise we would have had 
// two inheritance hierarchies, which would imply violating the type system! 
template<typename T>
struct template_meta_program : std::enable_if_t<sizeof(T) <= 4, meta_programming> {	// Inherits if the template size is
																					// less than equal four.
	void f() {
		//template_meta_program<int>::int_32 x;	// Fine!
		// template_meta_program<double>::int_32 y;	// Error, does not inherit from meta_programming.
	}
};

//int main() {
//}
