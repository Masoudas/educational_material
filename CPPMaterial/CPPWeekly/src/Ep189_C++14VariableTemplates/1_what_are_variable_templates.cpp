/**
* As is the case with templated types and functions, we can introduce a templated variable type as well.
* Notice that this would allow us to define the type of a constant for example.
* 
* Notice that the presence of braces imply that we can't define the type of pi as int, because there would
* be a narrowing conversion.
* 
* Finally, notice how we increase the precision of pi being displayed. The setprecision in iomanip
* takes care of this task for us.
*/
#include <iostream>
#include <iomanip>

template<typename T>
constexpr T pi = T{ 3.141592653589793238L };	// Type can't be int or bool due to {}, but can be float, double, long double.

template<typename T>
constexpr T g_pi = T(3.141592653589793238L);	// Now, can be float.

template<typename T>
const T value = T{ 1 };	// An integral value can be implicitly converted to many types, including bool, int, float

void using_the_variable_templates() {
	float f_pi = pi<float>;	// Cool
	long double ld_pi = pi<long double>;	// Cool

	// int i_pi = pi<int>; Error. A narrowing takes place.
	int i_pi = g_pi<int>;

	bool condition = value<bool>;	// Implicit conversion to bool. No narrowing!

	std::cout << std::setprecision(20) << "float pi is: " << f_pi << '\n';
	std::cout << std::setprecision(20) << "long double pi is: " << ld_pi << '\n';

}

//int main() {
//	using_the_variable_templates();
//}