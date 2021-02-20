/**
* (I have come across this one whilst investigating the for range loops, as discussed in the standard in 
* Statements_9.)
* 
* Apart from aliasing and templates, another place where we have the debacle of defining a reference to reference
* is with autos. 
* 
* As opposed to aliases, in autos, we actually put the && or & on the side of the auto saying 'auto&& r = v' and
* not using ref = type-id&& for example, which is deceiving at first. Note however that the same rules apply as
* in the case of aliases.
* 
* The oddest one in the lot is when we assign an object to auto&&. As we said, it's safe to assume that a var-name
* is in fact itself an lvalue. So it's clear now. We're having a &&& case, which will be interpreted as &.
* 
* Essnetially, autos never disappoint us, and they do their best to make sense of everything!
* 
* There's one very interesting place that this becomes handy. When passing an argument to a lambda, if we say
* auto&& val, then we can pass a temp. Now, if we pass a normal variable, it will be a reference to that.
* Initially, I thought this would work in functions too, but we can't do it, because we actually need to specify
* the type of the argument. It's only useful with lambdas! One other famous example is with range for loops, 
* where it's best to use aut&&.
*/
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

struct S {};

void type_deduction_with_auto_is_very_sophisticated() {
	int v{};
	int& lval = v;
	int&& rval = std::move(v);


	//int&& rval = lval; //Error! Assigning lvalue to rvalue!
	auto&& lval_1 = lval;	// This type is deduced as lval!
	auto& lval_2 = rval;	// Once again, lvalue wins
	auto& lval_3 = lval;	// Naturally!

	auto&& r_val_1 = std::move(v);	// Naturally
	auto&& r_val_2 = rval;	// What do you think?

	auto&& r_val_3 = v;

	// auto& s = S{}; Yep! This one is an error naturally! We can't assign rvalue to lvalue! This is one reason
	// why in for range loops we prefer to use auto&&. See the discussion in 7_3.
}

void defining_lambda_with_rvalue_ref() {
	vector<int> v{ 4, 2, 3, 1 };

	// Not the best example I have to say, because the lambda parameter should better be const, but whateves!
	std::transform(v.cbegin(), v.cend(), v.begin(), [](auto&& lhs) { return lhs + 1; });

	// Safest way to iterate using a range-for. See 7_3.
	for (auto&& x : v) {
		std::cout << x << '\t';
	}
}

//int main() {
//}