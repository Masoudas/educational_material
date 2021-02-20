/**
* Finally, we come to the comparison operators. Note that we always need all of <, <=, ==, >, >= and >. So, an
* interesting solution to avoid handwriting all of these operators one by one, it to use the spaceship operator
* introduced in C++20, to save some time.
* 
* Note that the use of spaceship operator is possible, so long as the fields of the class implement such ops. So,
* assuming we have ONLY a pointer in the underlying iterator, we can simply use the spaceship operator. Note if
* there are other fields in the class, such as for example an index i, then we need to check if it's still possible
* to use the operator. Otherwise, we have to implement the operators by hand.
* 
* Notice that we use the keyword default for this operator. Also notice that we use auto as the return type, which
* is more convenient to say the least (although perhas a bool would have been fine too.)
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
		++* this;	// Preferable to use the pre-increment operator.
		return _temp;
	}

	an_int_arr_itr& operator--() noexcept {
		--_ptr;
		return *this;
	}

	an_int_arr_itr operator--(int) noexcept {
		auto _temp = *this;
		--* this;
		return _temp;
	}

	an_int_arr_itr operator+(const difference_type size) const noexcept {
		auto _temp = *this;
		_temp._ptr = _ptr + size;
		return _temp;
	}

	friend an_int_arr_itr operator+(const difference_type size, const an_int_arr_itr& itr) {
		return itr + size;	// Easy!
	}

	an_int_arr_itr operator-(const difference_type size) const noexcept {
		auto _temp = *this;
		_temp._ptr = _ptr - size;
		return _temp;
	}

	friend an_int_arr_itr operator-(const difference_type size, const an_int_arr_itr& itr) {
		return itr - size;
	}

	an_int_arr_itr& operator+=(const difference_type size) noexcept {
		_ptr += size;
		return *this;
	}

	an_int_arr_itr operator-=(const difference_type size) {
		_ptr -= size;
		return *this;
	}

	auto operator<=>(const an_int_arr_itr& rhs) const noexcept = default;
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

	iterator_wrapper operator+(const difference_type size) const noexcept {
		auto _temp = *this;
		_temp._itr = _itr + size;
		return _temp;
	}

	friend iterator_wrapper operator+(const difference_type size, const iterator_wrapper& rhs) noexcept {
		return rhs + size;
	}

	iterator_wrapper operator-(const difference_type size) const noexcept {
		auto _temp = *this;
		_temp._itr = _itr - size;
		return _temp;
	}

	friend iterator_wrapper operator-(const difference_type size, const iterator_wrapper& rhs)  noexcept {
		return rhs - size;
	}

	iterator_wrapper& operator-=(const difference_type size) noexcept {
		_itr -= size;
		return *this;
	}

	auto operator<=>(const iterator_wrapper& rhs) const noexcept = default;

};