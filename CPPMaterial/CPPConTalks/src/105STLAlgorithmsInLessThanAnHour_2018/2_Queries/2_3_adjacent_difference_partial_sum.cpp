/**
* Read the descriptions below, which particulary teach us how to implement for loops with memory (depending on
* previous value, or writing to next value, etc).
* 
* adjacent_difference:
* Applies a binary operation to adjacent elements of a collection. For [a, b, c, ...], calculates
* [a, op2(b,a), op2(c,b), ...]. In other words, the first element remain in tact, and from the second one,
* first is subtracted from second, ... . Returns the iterator to element after last operated on. This operation
* is memoryless, not depending on newly calculated values.
* 
* partial_sum:
* Computes the partial sums of the elements in the subranges of the range [first, last) and writes them to 
* the range beginning at d_first. The first version uses operator+ to sum up the elements, the second version 
* uses the given binary function op, both applying std::move to their operands on the left hand side 
* (since C++20). The difference between adjacent difference is that calculated value of current element is 
* available for next iteration, making it ideal for cumsum.
* 
* 
*/
#include <numeric>
#include <vector>
#include <functional>
#include <execution>
#include <iostream>

void adjacent_summation_vec() {
	std::vector<int> v{ 1, 2, 3, 4, 5 };

	std::vector<int> v1(v.size());

	std::adjacent_difference(
		std::execution::par, v.begin(), v.end(), v1.begin(), std::plus<>{}
	);

	std::cout << "Adjacent sum is: \n";
	std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, "\t"));
}

/* Surprisingly enough, we can't compute the commulative sum with adjacent difference. Why? Because
the adjacent_difference takes a copy of current element, computes the binary op, then moves that current
value for the next operation! Therefore, when we use binary op, we're actually using the original value of
each position, not its cumsum!!!

However, we can trick this by writing to the next element the result of current and previous element. Hence
a_1 = a_0 and a_n+2 = a_n+1 + a_n. Therefore, we could calculate Fibbonaci for instance. Don't forget that we 
can't go till the end element with this scheme.

There's nothing to fancy about this loop, just the fact that current value is moved to val, saving us a copy.

out = *begin;
val = *begin;
while (++begin != end){
	temp = *begin;	// Copy of current element

	*++out = Function(val, temp);
	
	val = std::move(temp); // So the previous value is kept equal to previous iteration, saving us a copy.
}
++out;	// So that out points to end.
*/
void we_cant_compute_commulative_sum_but_we_can_fibonnaci_sequence() {
	// WRONG!
	std::vector<int> v(4, 1);
	auto output = std::adjacent_difference(
		v.cbegin(), v.cend(), v.begin(), std::plus<int>{}
	);

	std::vector<int> v1(5, 0);
	v1[0] = 1;
	auto o1 = std::adjacent_difference(
		v1.cbegin(), v1.cend()-1, v1.begin()+1, std::plus<int>{}
	);

	std::cout << "Fibonnaci sequence:\n";
	std::copy(v1.begin(), o1, std::ostream_iterator<int>(std::cout, "\t"));
}

/*
* Ok Wow! If we compare the implementation of this one with the last one, we see that the comparison is performed
* inside the for loop, meaning, first we move forward, then check we're not out of range, then we apply the op, and
* calculate the result. Then in the next iteration, we put the value in the current position. See how many ways 
* are out there to just implement a simple for loop!

// _Get_unwrapped unwraps a pointer from the iterator
auto _UFirst      = _Get_unwrapped(_First);	
const auto _ULast = _Get_unwrapped(_Last);
auto _UDest       = _Get_unwrapped_n(_Dest, _Idl_distance<_InIt>(_UFirst, _ULast));

if (_UFirst != _ULast) {
	_Iter_value_t<_InIt> _Val(*_UFirst);	// _Val is the value of the iterator.
	for (;;) {
		*_UDest = _Val;
		++_UDest;
		++_UFirst;
		if (_UFirst == _ULast) {
			break;
		}
	_Val = _Funct(_STD move(_Val), *_UFirst);	// The supplied function
	}
}
*/
void partial_sum() {
	std::vector<int> v(4, 1);
	auto output = std::partial_sum(
		v.cbegin(), v.cend(), v.begin(), std::plus<int>{}
	);

	std::cout << "Cummulative sum is :\n";
	std::copy(v.begin(), output, std::ostream_iterator<int>(std::cout, "\t"));
}


//int main() {
//	partial_sum();
//}