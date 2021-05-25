/**
* Don't overlook this very common pitfall. Say we have:
* int a;
* int b;
* 
* double c = (a + b) / 2;
* 
* This is incorrect, because a and b are integers and 2 is also an integer. Hence, (2 + 3) / 2 would be 2 (and
* not 2.5) before being set into c. So, always remember to write this expression as follows:
* double c = (a + b) / 2.0;
*/

#include <cmath>

/**
* Another common pitfall is the following. In this example, we're trying to calculate the third root of 0. 
* We know that this value is zero. Note also that the signature of the pow function is std::pow(double, double).
* Now, if we pass pow(0, 1/3), the second argument is int/int, which results in 0, and then pow(0,0). But we know
* that 0^0 = 1! So instead of getting 0, we get 1!! 
* 
* Always, always, and always, when writing double literals, write at least one with a dot "1.0" to ensure that
* such problems never occur! Preferably, write everything with a dot.
*/
void third_root_of_zero() {
	auto wrong_third = std::pow(0, 1 / 3);	// Oop! This is one! 0^0 = 0.
	auto right_third = std::pow(0, 1.0 / 3.0);	// Ok! 0^(0.333) = 0.
}
