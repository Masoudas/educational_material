/**
* Class members can themselves have their own templates. This will even extend to constructors, which
* will allows us to change different template types to one another.
* 
* In the following example, notice the use {} for memberwise initialization, which prevents any narrowing
* operations.
* 
* Also notice how we need to have getters, otherwise we can't have access to private members of another 
* template.
*/

template <typename T>
struct complex {
	complex(T re=0, T imag=0): re(re), imag(imag){}// Here, we use () and it's fine.

	complex(const complex<T>& ref) = default;	// Keep the default for copying same type objects.

	template<typename U>
	complex(const complex<U>& u) : re(u.get_re()), imag(u.get_imag()) {	// Get a reference to another type, 
		// and then initiate. Note the use of {}
	}

	T get_re() const { return re; }
	T get_imag() const { return imag; }

private:
	T re;
	T imag;
};

void casting_various_templates() {
	complex<float> cf; // default value
	complex<double> cd{ cf }; // OK: uses float to double conversion
	complex<float> cf2{ cd }; // error : no implicit double->float conversion
	complex<float> cf3{ 2.0,3.0 }; // error : no implicit double->float conversion
	complex<double> cd2{ 2.0F,3.0F }; // OK: uses float to double conversion
}