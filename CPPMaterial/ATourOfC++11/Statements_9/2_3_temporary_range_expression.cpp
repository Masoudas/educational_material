/**
* As we may have noticed, there's an odd expression in expansion of the for loop, where we say:
* auto && __range = range_expression;
* 
* What is it there for? Apparently, it's there to extend the life-time of temporaries. If it weren't there, we 
* would not be able to pass temporaries in the for loop. But this expression turns the temporary into a usable 
* lvalue. I know what you're thinking right now! You're thinking of the for loop in terms of a function, and 
* it could have gotten the range as an rvalue! But a loop is not a function, and what you write will be replaced 
* by the compiler as such! In conclusion, the rvalue is there to preserve temporaries.
* 
* Now, what's more interesting and terrifying is that if range_expression were an lvalue or a normal value, this 
* expression would not cause any issues, because it's defined with auto! For this, take a look at the example 
* below, where if we had used the actual type of the variable, we would have gotten into trouble. To understand why 
* this happens, take a look at Pointers_Arrays_References_7, auto_and_rvalue to understand why this expression 
* works the way it does. 
* 
*/

#include <list>;
using std::list;

void cant_use_lvalue_as_for_loop_range() {
	list<int> l{};
	list<int>& l1 = l;

	auto&& r = l1;	// list lvalue!
	//list<int>&& r = l1;	// This does not work though!


	for (auto val : r) {

	}

}

//int main() {
//	cant_use_lvalue_as_for_loop_range();
//}