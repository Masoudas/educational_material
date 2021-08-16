/**
* To get rid of the twisted logic discussed in the previous example, we can extract the logic of both const and non-const method
* into a common method. Then, we can use that method inside either method. As such, note that we may or may not have to deal
* with a const or non-const method. This is why we use a templated method to first extract the member, noting that whether or
* or not it has a const in it. Then, we use this common method to return.
* 
* Notice that we defined this method as static, so that it won't be a part of class definition.
* 
* Jason Turner implies that decltype(auto) is the inverse of a forwarding reference. That is, it returns the fully detected 
* type for us (including constness or reference.)
*/

struct expensive_obj{};

struct const_decl_auto {
	expensive_obj i_{};

	template<typename Self>
	static decltype(auto) common_i(Self* self) {
		return self->i_;
	}

	decltype(auto) return_i() {
		return common_i(this);
	}

	decltype(auto) return_i() const {
		return common_i(this);
	}

};

void using_const_decl_auto() {
	const const_decl_auto obj{};

	// Note: So far, MSVC detects this as simply expensive_obj. But in gcc this works correctly!
	// In any case, after compilation, if we try to assign to exp_obj, it throws a warning.
	decltype(auto) exp_obj = obj.return_i();
}