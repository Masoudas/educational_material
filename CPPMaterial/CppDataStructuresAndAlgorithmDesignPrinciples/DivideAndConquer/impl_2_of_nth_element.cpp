/**
* In this implementation, we create an iterator that goes over the elements of the median. So it will start from
* the first median, then jumps five elements to the next median (or it starts from first or second element and 
* then jumps to oblivion). Note that in this particular implementation, if there are more than one groups, and the
* last group is not 5, we won't take that last group into account, because we can't specialize the iterator for
* that last group.
* 
* In this schema, we get rid of the need for extra space. Moreover, we get rid of the need to linear search for 
* the location of pivot, because we know where it would be.
*/
#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
#include <iterator>

template<typename _RndItr>
class fifth_itr {
	_RndItr itr;

public:
	using iterator_category = typename _RndItr::iterator_category;
	using value_type = typename _RndItr::value_type;
	using difference_type = typename _RndItr::difference_type;
	using pointer = value_type*;
	using reference = value_type&;

	fifth_itr(_RndItr itr) : itr{ itr } {}

	auto& operator*() const {
		return *itr;
	}

	fifth_itr& operator+(const difference_type i) noexcept{
		itr = itr + 5 * i;
		return *this;
	}

	friend fifth_itr operator+(const difference_type i, const fifth_itr& rhs) noexcept {
		return rhs + 5 * i;
	}

	friend fifth_itr operator-(const difference_type i, const fifth_itr& rhs) noexcept {
		return rhs - 5 * i;
	}

	friend fifth_itr operator-(const fifth_itr& rhs, const difference_type i) noexcept {
		return rhs - 5 * i;
	}

	fifth_itr& operator+=(difference_type i) noexcept{
		itr += 5 * i;
		return *this;
	}
	
	fifth_itr& operator++() noexcept {
		itr += 5;
		return *this;
	}

	fifth_itr& operator--() noexcept {
		itr -= 5;
		return *this;
	}

	fifth_itr operator++(int) const noexcept {
		fifth_itr temp{ *this };
		++itr;
		return temp;
	}

	fifth_itr operator--(int) const noexcept {
		fifth_itr temp{ *this };
		--itr;
		return temp;
	}

	bool operator==(const fifth_itr& rhs) {
		return itr == rhs.itr;
	}

	bool operator!=(const fifth_itr& rhs) {
		return !(*this == rhs);
	}

	bool operator<(const fifth_itr& rhs) {
		return itr < rhs.itr;
	}

	bool operator>=(const fifth_itr& rhs) {
		return !(*this < rhs);
	}

	pointer operator->() const noexcept {
		return itr;
	}

	friend difference_type operator-(const fifth_itr& lhs, const fifth_itr& rhs) {
		return (lhs.itr - rhs.itr) / 5;
	}

	friend bool operator!=(const fifth_itr& lhs, const fifth_itr& rhs) {
		return !(lhs == rhs);
	}

	friend bool operator==(const fifth_itr& lhs, const fifth_itr& rhs) {
		return lhs.itr == rhs.itr;
	}

};

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
	size_t N = std::distance(_First, _Last);
	if (_First == _Last || N <= 1) return _nth;

	for (size_t i = 0, j = 0; i < N; i += 5) {
		j = std::min(i + 5, N);
		_RndItr _Five_First = std::next(_First, i);
		_RndItr _Five_Last = std::next(_First, j);

		median_five(_Five_First, _Five_Last, j - i);
	}

	int b = 0, e = 0;
	if (N >= 3) {
		b = 2;
		e = 2 + (N / 5) * 5;
	}
	else { // N can only be two
		b = 1;
		e = 1 + 5;
	}

	fifth_itr begin_five{ _First + b };
	fifth_itr end_five{ _First + e };

	// Compute the median of medians using recursion of this function.
	size_t N1 = std::distance(begin_five, end_five);
	fifth_itr m_m = begin_five; std::advance(begin_five,  N1 / 2);
	nth_element_impl_1(begin_five, m_m, end_five);

	std::swap(*_First, *m_m);	// Swap it with the beginning element.
	_RndItr m_m_position = my_partition(_First, _Last);

	// Compare iterators and reperform sorting if necessary.
	if (m_m_position == _nth) {
		return _nth;
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
//	int index = 2;
//	nth_element_impl_1(v1.begin(), v1.begin() + index, v1.end());	// Find the first element.
//
//	std::cout << "The element at location " << index + 1 << " is: " << *(v1.begin() + index);
//
//}
