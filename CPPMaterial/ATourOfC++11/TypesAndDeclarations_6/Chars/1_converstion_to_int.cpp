/**
* Me: As we know, a char is in fact an integer value. However, its value can be interpreted as an ASCII char
* by printf or ostream class. In particular, ostream by default prints chars by ASCII content, and we need a
* conversion to int if we want the value.
* 
* As the big guy says: When it comes to chars, it's not safe to assume that chars are contiguous.
* 
* We may say char c = 'b'; int i {c}; The question however is that whether c is signed or unsigned, is it
* implemented with one's complement or two's complement (hence, range from -127 to 127 or -128 to 127).
* So even cast is not trivial. Best to use the home made cast function Mr.Bjrane talks about.
* 
* Note however that the standard says that "For every value of type unsigned char in range [0, 255], 
* converting the value to char and then back to unsigned char produces the original value"
* 
* As we said the following cast is undefined:

char c = 255;
int i = c;

* Because we don't know whether c (which is all one) is actually -1 or 255. In other words, 255 is an int literal,
* then converted to int, which if c is unsigned is 255, otherwise -1.
* Me: Actually, this not a problem of conversion from char to int, but rather the problem of int to char. The
* standard says "char can be converted to int or unsigned int depending on the underlying type." And it further
* states that "unsigned char, char8_t (since C++20) or unsigned short can be converted to int if it can hold 
* its entire value range, and unsigned int otherwise." Perhaps there's a system for which char is 32 bits, 
* otherwise I can't think of a practical case where char can't be converted to int directly.
* 
* Naturally of course int i = 'c' is not allowed.
*/

//#include <stdio.h>	
#include <iostream>

void printing_chars() {
	char c = '8';
	printf("'%i' is the int value and '%c' is the char value of the char\n", c, c);

	std::cout << c;
}

//int main() {
//	printing_chars();
//}


