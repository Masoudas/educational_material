/**
* Supposing an iterator is random access, we can define operators that take integer values for addition and 
* subtraction. Question is, should we use size_t or int for these, or perhaps something else?
* 
* Ok. The answer to this question is quite interesting. Note that we know that the difference of the underlying
* value type is difference_type. So, we use difference_type as the argument to such an operator. More precisely,
* we do this because difference_type = itr1 - itr2, therefore, difference_type - itr1 = -itr2, or that also
* difference_type + itr2 = itr1.
* 
* Finally, note that as soon as we write operator+ and operator-, we can simply write operator-= and operator +=
* as well.
* 
* Question: What happens if someone writes itr - (-5) in such a case? So, assuming that the difference_type is for
* example ptrdiff_t, then it will indeed increase by 5. So, it depends on the underlying difference_type.
* 
* A final thought is that because we always need 5 + itr as well as itr + 5, it's best to define both, and first
* one as friend operator and second as member function. Note also that operator+ and operator- are const noexcept
* operators (they return a new type), whereas operator+= and operator-= are both only noexcept types. 
* Notice the interesting thing when writing the operator+(). We first create a copy, then add the size to that
* copy. This makes our current operator const, hence, const noexcept label!
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

	friend iterator_wrapper operator-(const difference_type size, const iterator_wrapper& rhs) noexcept {
		return rhs - size;
	}

	iterator_wrapper& operator-=(const difference_type size) noexcept {
		_itr -= size;
		return *this;
	}
};