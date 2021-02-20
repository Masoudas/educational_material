/**
* There's a very interesting observation regarding templates. The instantiation of one type is completely
* independent from another. In the sense that even inside the class definition, a template of one type
* can't access the private fields of another template!
* 
* This can be illustrated with the example below:
*/
template <typename SCALAR>
class Complex {
	SCALAR re, im;

	template <typename T>	// Template is different from SCALAR. Hence, instantians are
							// potentially different from SCALAR!
	Complex(const Complex& ref) : re(ref.re), im(ref.im){}	// WRONG! ref is from a different template type.
															// Hence, this definition cannot access it.
};