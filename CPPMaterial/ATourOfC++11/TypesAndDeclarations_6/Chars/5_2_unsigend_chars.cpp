/**
* Me: So if we've learned one thing, it's that char literals are char in C++ (int in C apparently.) 
* 
* Of course, we said that char can be signed or unsigned in C++.  The question however is that what happens
* to unsigend chars? For example, would they print a char in cout?
* 
* Note that the original ASCII table has 127 chars. However, the ASCII table also has an extended table as 
* well, going all the way to 255, where 254 is a square, and 255 is a blank char. 
* 
* So what they've done is that 255 is wrapped to -1. So, it does not matter if I try to
* print -1 or 255, they print the same thing. Of course value-wise, they're different. But representation
* wise, they're the same thing, and printing them both results the same thing. This is the reason why when
* streaming these chars, we actually static_cast or reinterpret cast their types or pointers to one another.
* Note that this must not be compiler dependent, because the ASCII table talks about bit representation.
* 
* Of course, again note that the values are not the same, but the chars they represent is.
*/

#include <iostream>

/*
int main() {
	unsigned char u = 254;
	signed char s = -2;
	std::cout << s << " " << u;

}
*/

