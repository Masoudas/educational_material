/**
* As we may recall, we may:
*	-	Pass parameters in lambda as reference
*	-	Pass them as copies 
*	-	Use type deduction to generate new params
* For example, below i is deduced as int, y is passed as reference, this is passed as copy, and also an 
* instance of S is generated. Notice that because y is not passed as reference, it's actually copied, whereas
* char32_t is actually copied.
* 
* The point to remember is that:
*	-	All that's passed are deduced. We can't declare types for them.
*	-	Everything that's not passed as reference is const.
*/

struct S {
	void capture_in_lambda() {
		char y = 'c';
		char32_t c32 = 'a';
		auto l = [i = 0, s = S{}, ptr = this, y, &c32](){
			c32 = 'd';
		};
	}
};
