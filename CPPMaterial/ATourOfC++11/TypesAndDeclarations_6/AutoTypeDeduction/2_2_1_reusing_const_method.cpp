/**
* Consider the const_auto class. We see that for the const method, we return a const auto& to avoid an expensive copy, and for
* non-const method, we just return a reference to the object.
*
* Now, suppose for some reason, we want to have the same logic among return and return_i. Normally, in such cases it's best
* to use the const method in the non-const method. The problem however is that we require a cast from const return type of the
* const method, because the signature of the non-const method returns only a reference. As such, we'd require something like
* this:

auto& return_i(){
	return const_cast<expensive_obj&>(static_cast<const const_auto*>(*this).return_i());
}

* In other words, what we do above is to cast the 'this' pointer into a const pointer, so that we could have access to the 
* const method! Then, what we do is to simply use the const method, and then to change the constness of the result, we need
* only to use const_cast method.
* 
* This is a funny piece of code, but essentially, we're not supposed to use constant cast. Next, we shall demonstrate how to
* remedy this problem using decltype(auto).
* 
*/

struct expensive_obj {};

struct const_auto{
	expensive_obj i_{};

	auto& return_i() {
		return i_;
	}

	const auto& return_i() const {
		return i_;
	}
};

