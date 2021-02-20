/**
* As of C++20, there's a new operator called threeway comparison, denoted as <=>, which allow us to 
* add default comparisons. We can declare the comparisons as constexpr or whatever, and by including
* the compare header, they're automatically filled by the compiler. Notice the addition of default after
* the definition, which allow us to use default comparisons for the type.
* 
* What this operator does is that it adds element-wise comparison for the invariants of the class. 
* 
* Note finally that we don't need to say the operator is constexpr. The compiler takes care of this for us.
* Morever, we don't need to define the friend function for the expression 42 < intWrapper. This operator
* is also implicitly generated (just note that for it to work, we need to add a constructor. It does not
* work with memberwise initialization).
*/

#include <compare>

struct intWrapper {
	int val;
	constexpr intWrapper(int val) : val{val}{}
	auto operator<=>(const intWrapper&) const noexcept = default;

};

constexpr bool is_lt(const intWrapper& lhs, const intWrapper& rhs){
	return lhs < rhs;	// Comparator is by default constexpr
}

void using_intWrapper_comparison_operators() {
	intWrapper w1{ 10 };
	intWrapper w2{ 20 };

	w1 < w2; w1 == w2; w1 != w2;
	auto comp = 42 < w1;	// Works, but needs a constructor!
}