/**
* An important motivation behind creating a span is to acquire subspan on that span, which a view of the 
* original data. See the following example on using span to create squared-root transformation of the original
* span.
*/
#include <span>
#include <algorithm>

void square_but_first_and_last(std::span<int> sp) {
	auto sub_sp = sp.subspan(1, sp.size() - 1 - 1);	// A subspan from the first to the last element minus one.

	std::transform(sub_sp.begin(), sub_sp.end(), sub_sp.begin(), [](const int& i) { return i * i; });

	// Alternatively:
	for (auto&& val : sp.subspan(1, sp.size() - 1 - 1)) {
		val = val * val;
	}
}