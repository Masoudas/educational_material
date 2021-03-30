/**
* Imagine that there's no min or max for the given symbol table (the table is empty). How would we deal with 
* such a situation?
* 
* Well for example in C++, there are no such min or max, and we need to find min and max in other ways (iterators
* are the perfect way to do so.) Now, if we use iterators, then they'd point to end, and our task is complete.
* However, in the implementations we do here, we throw exceptions for such cases.
*/

// #include <unordered_map> Nope
#include <map>	// Map is ordered

void getting_min_max_from_ordered_table(const std::map<int, const char*>& m) {
	if (!m.size()) {
		throw "Ordered map size is zero, has no min or max";
	}
	//	m.min(); m.max();		Error! No such methods.
	auto begin = m.cbegin();
	auto min = *begin;	// Ordered with a less method.

	while (++begin != m.cend());	// Add to the iterator, then compare to end.
	auto max = *--begin;	// Go back one step from end, then compute the value (note that -- has higher
							// priority here.
}