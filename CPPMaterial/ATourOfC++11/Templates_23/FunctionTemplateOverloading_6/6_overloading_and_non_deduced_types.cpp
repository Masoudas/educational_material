/**
* Whereas we can't have any implicit conversion with templated types (it would be meaningless for the compiler to
* convert cons char* to string for a templated type), if a function has templated and non-templated arguments,
* conversion is applied for non-templated types, as usual!
* 
* This notation is sometimes called explicit specialization.
*/
#include <vector>
template<typename T, typename C>
T get_nth(C& p, int n) { return T{}; }; // get the nth element

struct Index {
	operator int() { return 0; };
	// ...
};

void conversion_applies_to_non_templated_types(std::vector<int>& v, short s, Index i)
{
	int i1 = get_nth<int>(v, 2); // exact match
	int i2 = get_nth<int>(v, s); // standard conversion: short to int
	int i3 = get_nth<int>(v, i); // user-defined conversion: Index to int
}