/**
* In a big picture view, courtesy of yours truly, an expression containing <=> introduces an (weak, partial
* or strong) ordering. In other words, when the compiler sees an expression x <=> y, it produces a signed char
* equivalent to -1, 0, +1 or -128, corresponding to less, equal, greater, or unordered.
*
* Saying 4 <=> 5 generates an xxx_ordering (usually strong) and keeps that signed char internally. For example,
* for 4 <=> 5, that value is -1, because 4 is strictly less that 5. But for example 4 <=> 4 is 0. 
* 4 <=> 5 --> -1 (meaning left hand side is less than right hand side)
* 5 <=> 4 --> 1 (meaning left hand side is greater than right hand side)
* 5 <=> 5 --> 0
* 
* Now, there are three pretty enums here, where _Compare_t is an alias for signed char:
*	-	enum class _Compare_eq : _Compare_t { equal = 0, equivalent = equal };
*	-	enum class _Compare_ord : _Compare_t { less = -1, greater = 1 };
*	-	enum class _Compare_ncmp : _Compare_t { unordered = -128 };
* Therefore, stdstrong_order::less < 0 is true for example. Each xxx_ordering has less, equal, equivalent and
* unordered as STATIC member classes. Why? So that we can either say
* 
* 4 <=> 5 == less OR 4 <=> 5 < 0.
*  
*/
#include <compare>
#include <iostream>

void some_concrete_results_of_comparison() {
	bool o1 = (4 <=> 5) < 0;	// True, because -1 < 0 is true.
	bool o2 = (5 <=> 4) > 0;	// True, because 1 > 0 is true.
	bool o3 = (5 <=> 5) == 0;	// True, because 0 == 0 is true.

	std::strong_ordering s_order = 4 <=> 5;	// A strong ordering type (a==b --> f(a)=f(b) and one of <, =, >,... 
										// is true.

	if (s_order < 0 && s_order == std::strong_ordering::less) {
		std::cout << "Both \'s_order < 0\' and \'s_order == std::strong_ordering::less\' return the same\
 result, which is 4 is less than 5";
	}

}

//int main() {
//	some_concrete_results_of_comparison();
//}


