/**
* As of C++20, we can introduce templates to lambdas. Take a look at Episode 184 for a particularly interesting
* use of variadic templated lambda functions together with higher order functions. This example shows us why
* just having lambdas is not enough and we needed templates.
* 
* Generally, we need templates to allow for more specific function definitions.
* 
* One question is, compared to using auto, wouldn't using templates cause more code bloat? It's a good question.
* I think the answer has to be no, because even with auto, I think we generate specializations of a particular
* set of parameters at run-time too.
* 
* Also, note that the lambdas are placed after brackets, and we don't use the template keyword!
*/

#include <vector>

void templated_lambdas() {
	auto lambda = []<typename T>(const std::vector<T> v) {
		return v.size();
	};
}
