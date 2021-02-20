/**
* Splice after is used for MOVING (and not copying) the elements of one list into another. Two overloads of this method
* are very important:
* 
* void splice_after( const_iterator pos, forward_list& other );
* void splice_after( const_iterator pos, forward_list&& other );
* void splice_after( const_iterator pos, forward_list& other, const_iterator first, const_iterator last );
* void splice_after( const_iterator pos, forward_list&& other, const_iterator first, const_iterator last );
* 
* AS is clear, these methods place the elements of the other list after the position we give to the method. Why
* is it called splice? Splice means join or connect (a rope or ropes) by interweaving the strands. Note that as is
* the case with iterators and insertion, first is not copied into the new list.
*/
#include <iostream>
#include <forward_list>

void splicing_two_forward_lists() {
	std::forward_list<int> f1{ 1, 2, 3 };
	std::forward_list<int> f2{ 4, 5, 6 };

	auto third_pos = f2.begin();
	std::advance(third_pos, 2);
	f1.splice_after(f1.begin(), f2, f2.cbefore_begin(), third_pos);

	std::cout << "Spliced list is [1, 4, 5, 2, 3]\n";
	std::copy(f1.cbegin(), f1.cend(), std::ostream_iterator<int>{std::cout, " "});

	std::cout << "\nAnd the other list [6]\n";
	std::copy(f2.cbegin(), f2.cend(), std::ostream_iterator<int>{std::cout, " "});
}

//int main() {
//	splicing_two_forward_lists();
//}