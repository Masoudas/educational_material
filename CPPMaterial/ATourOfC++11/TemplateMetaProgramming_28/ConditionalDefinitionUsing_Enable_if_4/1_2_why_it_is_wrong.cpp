/** Me:
* Now, The piece of code the big seems to give is wrong:

template<typename T>
struct get_f_result {
private:
	template<typename X>
	static constexpr auto check(const X& x) -> decltype(the_function_f(x)) {}; // can call f(x)

	static constexpr substitution_failure check(...) {}; // cannot call f(x)
};

* The problem with this piece of code is that: 
*	1-	I don't know what the three dots represent. 
*	2-	Say I write const X& in place of three dots. Not, if decltype fails, it's true that the second
*		overload is chosen. However, if it succeeds, we'll have a repetition of function declaration!
* 
* There's seems to be an enable_if missing from this definition somewhere. I tried so many ideas, but I failed.
* The issue to solve is to define a second overload that would be used when the first one fails, or enable 
* something in case the first one fails. This is beyond my level at this point.
* 
*/