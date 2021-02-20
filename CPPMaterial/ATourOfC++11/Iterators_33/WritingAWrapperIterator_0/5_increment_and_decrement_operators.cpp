/**
* One thing to note about increment and decrement operators is that in post increment, the argument has to be of 
* type int, otherwise we get a compile-time error. Once, I accidentally used size_t as an argument, and the compiler
* gently reminded me that I shouldn't have!
* 
* Note that we add noexcept to these operators, but not const.
* 
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

	an_int_arr_itr& operator++() noexcept {
		++_ptr;
		return *this;
	}

	an_int_arr_itr operator++(int) noexcept {
		auto _temp = *this;	// Using the copy ctor here.
		++*this;	// Preferable to use the pre-increment operator.
		return _temp;
	}

	an_int_arr_itr& operator--() noexcept {
		--_ptr;
		return *this;
	}

	an_int_arr_itr operator--(int) noexcept {
		auto _temp = *this;	
		--*this;	
		return _temp;
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

	iterator_wrapper& operator++() noexcept {
		++_itr;
		return *this;
	}

	iterator_wrapper& operator++(int) noexcept {
		auto _temp = *this;
		++_itr;
		return _temp;
	}

	iterator_wrapper& operator--() noexcept {
		--_itr;
		return *this;
	}

	iterator_wrapper operator--() noexcept {
		auto _temp = *this;
		--_itr;
		return _temp;
	}
};