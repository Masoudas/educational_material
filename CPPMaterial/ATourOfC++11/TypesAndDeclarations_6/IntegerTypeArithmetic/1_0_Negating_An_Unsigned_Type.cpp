/**
* Let's say I have an unsigned typpe. What happens when I negate it and assign it back to the same
* unsigned variabel?
* So this would be like saying -1 * value. -1 Is promoted to unsigned, then multiplied by the value.
* So in the following example, -1 with 32 bit is 0xFFFFFFF times 1 is the maximum! 
* However, VS does not allow me to perform this, and returns a compilation error!
* 
* Same question, but assigning it to a signed value? Again, -1 is promoted to unsigned, multiplied
* and result is put in the new variable. But then again, VS does not allow me to do this.
* 
*/
#include <iostream>
void negating_an_unsigned_type() {
	unsigned int x = 1;
	//x = -x;
	//long y = -x;

	std::cout << "Negating unsigned 1 results in: " << x;
}

//int main() {
//	negating_an_unsigned_type();
//}