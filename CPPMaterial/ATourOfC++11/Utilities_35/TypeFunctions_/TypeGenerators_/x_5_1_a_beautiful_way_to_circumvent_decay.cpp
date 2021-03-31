/**
* This is all me:
* 
* Now here's the rub. Suppose we're working with a decay_t, for example a function that returns a decay_t
* type. However, we want trick it into returning a reference, even though it removes the cv qualifier. So,
* How can we do that? This is the signature of such a function:
* 
* template<typename T>
* decay_t<T> decayer(T t);	// No cv or reference qualifiers, hence no reference is returned.
* 
* Naturally, the answer is that we have to wrap it another type, and that underlying type keeps our original
* value. Hence, when we access this new type, we access the underlying type by reference. Essentially, we 
* need a wrapper around the original type. But here's the rub. Let's call this new type 'reference_wrapper'
* Someone who works with a code does not want to have to deal with reference wrapper. So if they have given
* a type T&, they want a type T& back. This means that casting from reference_wrapper to T& must be effortless.
* In other words, reference_wrapper must implement a cast to T&. And voila, we've figured out what we want:
* 
* decay_t<reference_wrapper<T>> x;
* T& y = x;	// An implicit conversion! 
* 
* So with that in mind, below we've implemented such a class. See next how C++ implements this class and how
* we can convert to it.
* 
* Note: If someone passes rvalue ref to this, this code still works fine. But the implementation of standard
* is still different.
*/

template<typename T>
struct reference_wrapper {
	using type = T;	// Just to recall what the pure type of the underlying type is for the user.

	type& val;

	reference_wrapper(T&& t) {
		val = t;
	}

	// Implicit cast to type&
	operator type& () {
		return val;
	}
};