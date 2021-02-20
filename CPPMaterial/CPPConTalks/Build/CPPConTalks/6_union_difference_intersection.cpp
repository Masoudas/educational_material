/**
* Before we begin, we should remember that these algorithms are not meant for sets. This is because sets don't
* have push_back methods, and moreover, they're not ordered, which is fundamental for the following algorithms.
* This is in spite of the fact they all have 'set' as part of their names.
* 
* Note that there's an equivalent version in the ranges header.
* 
* Ok. The set_union algorithm has the following interfaces:
* OutputIt set_union( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first )
* constexpr OutputIt set_union( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first, 
*	Compare comp );
* 
* Now, the union algorithm computes the union of the two sets. It DOES NOT add one set to another, but rather just keeps
* the new elements. However, if an element is present m-times in first and n-times in second range, then all n instances
* will be copied, but only max{n-m, 0} will be copied from the first, and the order is preserved for both. This is why
* if they have only one repeated element, it will not be copied from the first set. In other words, the number of appearences
* of the elements would be max{n,m}.
* 
* Now here's something very interesting. There's a function in iterator header called std::back_inserter(dest1). This
* baby is kind of amazing, in the sense that if we supply it with a push_back like function, it returns an iterator, 
* which can be used, well, as an iterator for inserting elements inside the collection. KOOL! So now, we actually 
* supply the union function with these iterators, so that we don't have to first create a collection.
* 
* With intersection, if an element is present m times in first and n times in second, then min{n,m} of elements will be copied
* from THE FIRST set only. 
*/
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

void back_inserter_in_action() {
	std::vector<int> v1{ };

	auto itr = std::back_inserter(v1);
	*itr = 1;
	itr++;

	*itr = 2;
	std::copy(v1.cbegin(), v1.cend(), std::ostream_iterator<int>{std::cout, "\t"});
}

void union_of_collections() {
	std::vector<int> v1{ 1, 2, 3 };
	std::vector<int> v2{ 2, 5, 6 };

	std::vector<int> v3{};	// We can't reserve, because we don't know what the size of union would be.

	std::set_union(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend(), std::back_inserter(v3));

	std::copy(v3.cbegin(), v3.cend(), std::ostream_iterator<int>{std::cout, "\t"});
}

void intersection_of_collections() {
	std::vector<int> v1{ 2, 2, 2, 3 };
	std::vector<int> v2{ 2, 3, 6 };

	std::vector<int> v3{};	// We can't reserve, because we don't know what the size of union would be.

	std::set_intersection(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend(), std::back_inserter(v3));

	std::copy(v3.cbegin(), v3.cend(), std::ostream_iterator<int>{std::cout, "\t"});
}

//int main() {
//	intersection_of_collections();
//}