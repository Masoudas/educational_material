/**
* One work-around for template type checking with templates would be to define the constructor
* with its own template parameter! Yes. C++ allows this, and we can that way assign templates 
* of different type to each other. Note that the way we initialize the invariants with {} in copy constructor
* allow us to protect against narrowing conversions.
* 
* One thing else that we learn here is that overloading a function with a new template parameter
* is possible.
* 
* IMPORTANT QUESTION: For some ungodly reason, in the copy constructor with template, if I decalre the
* to copy argument as const, it will not allow me to access the real and imag method. Why? This is not the
* case with Bjarne, where he writes the copy constructor as complex(const complex<T> c) !!!
*/

template <typename SCALAR>
class complex {
	SCALAR re, im;
public:
	template<typename T>
	complex(T re, T im) : re(re), im(im) {}

	//complex(const complex<SCALAR>& c) = default;	// For normal copies.

	template<typename T>
	complex(complex<T>& c) : re{ c.real() }, im{ c.imag() } {
		// Check the next item to see why the getter methods are crucial here.
	}

	SCALAR real() { return re; }
	SCALAR imag() { return im; }
};

void circumventing_compile_time_type_check() {
	complex<float> c1{ 1.1f, 2.2f };
	complex<double> c2{ c1 };	// Using our copy constructor.

	complex<double> c3{ c2 };	// Using default constructor.
	
}

//int main() {
//	circumventing_compile_time_type_check();
//}