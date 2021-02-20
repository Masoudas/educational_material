/**
* In this implementation, we're going to go berzerk, and use a helper array to save the medians, which is then used
* to identify the median of medians.
* 
* Here's a subtle issue. How can we determine the median of medians of this vector?
* The answer is, you guessed it, we call the same algorithm, but this time we pass this vector and search for the
* middle element of it! Nice! See finding the median of a container.
* 
* So we have an issue here. First, note that the partition depends on the fact that the pivot is the first element.
* We can tamper with the partition, but then we can't change elements on equality, which degrades the performance
* (or perhaps not, but the original partitioning in Sedgewick states that we have to change). Now, to set the pivot
* in the beginning, we need to know the location of the median of medians, which is not straight forward, because
* the order of the median of median vector changes in a call to the position finder function. So, we have to find 
* the location of the median, which is O(n)! So we see that there's no way around this. Hence, the only solution
* is to write the partition algorithm in such a way that when we arrive at an equal element, we don't stop. But
* still, I can't put the partition element unless I knew it's location, but I don't! 
* 
* I also checked the implementation of the book, and it's wrong. They make a mistake when they pass the iterator
* of median of medians to the partitioner as position of the median! I guess in this implementation, there's no
* way around it other than performing a linear search for the pivot.
* 
* A final note is that the search could be the fifth of what it is, if we looked for every fifth element of the
* iterator. But we just use the standard find method, and instead go to implementation two.
* 
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

template<typename _Itr>
_Itr my_partition(_Itr begin, _Itr end) {
	if (std::distance(begin, end) <= 1) return begin;
	
	auto v = *begin;
	_Itr i = begin; _Itr j = end;
	while (true)
	{
		while (++i != end && *i < v); // No equal comparison. If equal, we break.
		while (v < *--j); // No equal comparison. If equal, we break.

		if (i >= j) break;

		std::swap(*i, *j);
	}

	std::swap(*begin, *j);

	return j;
}

template<typename _RndItr>
auto median_five(_RndItr _First, _RndItr _Last, size_t N) {
	std::sort(_First, _Last);	// Sort this portion.

	std::advance(_First, N / 2);
	return *_First;
}


template<typename _RndItr>
_RndItr nth_element_impl_1(_RndItr _First, _RndItr _nth, _RndItr _Last) {
	using _UW_Type = std::remove_reference_t<decltype(*_First)>;

	size_t N = std::distance(_First, _Last);
	if (_First == _Last || N <= 1) return;

	std::vector<_UW_Type> medians{};
	for (size_t i = 0, j = 0; i < N; i += 5) {
		j = std::min(i + 5, N);
		
		_RndItr _Five_First = std::next(_First, i);
		_RndItr _Five_Last = std::next(_First, j);

		medians.emplace_back(median_five(_Five_First, _Five_Last, j - i));
	}

	// Compute the median of medians using recursion of this function.
	auto m_m = medians.begin(); std::advance(m_m, medians.size() / 2);
	medians.size() == 1 ? _First : nth_element_impl_1(medians.begin(), m_m, medians.end());

	auto loc = std::find(_First, _Last, *m_m);	// Find the corresponding location of the median of medians
	std::swap(*_First, *loc);	// Swap it with the beginning element.

	_RndItr m_m_position = my_partition(_First, _Last);

	// Compare iterators and reperform sorting if necessary.
	if (m_m_position == _nth) {
		return;
	}
	else if (m_m_position < _nth) {
		return nth_element_impl_1(++m_m_position, _nth, _Last);
	}
	else {
		return nth_element_impl_1(_First, _nth, m_m_position);

	}
}


//int main() {
//	std::vector<double> v1{ 5.0, 7.0, 4.0, 6.0, 3.0, 2.0, 1.0, 8.0 };
//	
//	int index = 7;
//	nth_element_impl_1(v1.begin(), v1.begin() + index, v1.end());	// Find the first element.
//
//	std::copy(v1.begin(), v1.end(), std::ostream_iterator<double>{ std::cout, "\t" });
//	
//}