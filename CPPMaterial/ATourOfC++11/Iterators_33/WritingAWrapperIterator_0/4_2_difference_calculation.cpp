/**
* Answer to question two:
* After having determined the type of the difference result, the question is, how do we calculate the 'itr1 - itr2'
* expression? To do so, we naturally need to define a function (more precisely an operator) that would take the
* arguments and is a operator- that returns a difference_type value.
* 
* Should this operator be defined as a class member, or a stand-alone function? Given that we always work with an
* instance (itr1), it's perfectly acceptable to define this difference as a member function.
* 
* Note: Whenever possible, don't forget to use const and noexcept.
*/

#include <xutility>
#include <cstddef>

class an_int_arr_itr {
public:
	using iterator_category = std::contiguous_iterator_tag;

	using value_type = int;
	using pointer = value_type*;
	using reference = value_type&;

	using difference_type = std::ptrdiff_t;	// What is the result of pointer - pointer? It's ptrdiff_t.

private:
	pointer _ptr;

public:
	difference_type operator-(const an_int_arr_itr& rhs) const noexcept {
		return _ptr - rhs._ptr;
	}
};

template<typename _Itr>
class iterator_wrapper {
public:
	using iterator_category = typename _Itr::iterator_category;

	using value_type = typename _Itr::value_type;
	using reference = typename _Itr::reference;
	using pointer = typename _Itr::pointer;

	using difference_type = typename _Itr::difference_type;	// Just drag the difference type of the underlying itr.

private:
	_Itr _itr;

public:
	difference_type operator-(const _Itr& rhs) {  
		// It's as simple as calculating the difference of the underlying itr.
		return _itr - rhs._itr;
	}
};