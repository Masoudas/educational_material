/**
* Higher order functions are those functions that take functions as argument or return functions as argument.
* 
* Consider the following templated example, where we calculate f of g, using a templated higher order function.
* For f(g()) to work, the return type of g has to be valid for f. In fact, we create a lambda that calculates
* f of g. Notice how we use auto to return the lambda (see Ep. 249).
* 
* To make matters more interesting, let's assume that g takes arbitrary arguments. The goal is to create a 
* lambda that computes f(g(...)) and returns the result.
*
* The following example demonstreates how we create this lambda. Note how we use variadic arguments as input
* function argument for the lambda. Therefore, the lambda would require these parameters, and fog would be
* calculated using said variadic arguments.
* 
* Essentially, these would allow bind front and back, and we can lazyly evaluate results.
*/
#include <utility>

template <typename F, typename G>
auto f_of_g(F&& f, G&& g) {
	auto lambda = [f = std::forward<F>(f), g = std::forward<G>(g)]<typename ... Args>(Args...args)->auto{
		return f(g(args...));
	};

	return lambda;
}

int expensive_function(int, int, int) { return {}; };
int even_more_expensive_function(int) { return {}; };
//
//int main() {
//	auto fg = f_of_g(std::move(even_more_expensive_function), std::move(expensive_function));
//
//	int result = fg(1, 2, 3);
//}