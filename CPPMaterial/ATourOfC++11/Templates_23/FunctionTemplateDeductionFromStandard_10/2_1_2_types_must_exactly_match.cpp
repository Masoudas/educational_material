/** This is from me:
* Here's something very important regarding template deduction: The Ps have to be exactly equal in type,
* and even implicit conversions are not allowed!
* 
* This goes to the observation that I've had about C++, in that the compiler does not do two things together.
* If it determines a type here with dedcution, it does not go the extra step of determining a common type
* for the parameters.
*
* Consider for example:

template<typename T>
void f(T t1, T t2);

* None of the following work:
* f(1, 1.1);	P1 = int, P2 = double
*				Error! Can't be deduced (int or double, even though there's a conversion)
* f(base, derived);	P1=base, P2=derived. Error!
* f(1ul, 1);	Error! unsigned long or int!
*/


