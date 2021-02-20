/**
 * We know that the case statements must be CONSTANT and INTEGRAL, or enumeration (so no double for example).
 * Never forget that switch carries out to the next statement, unless it's terminated (by break, or return, ...)
 *
 * default case is not necessary.
 */

 /**
  * If we consider this example:
  */
#include <string>
//void f(int i)
//{
//	switch (i) {
//	case 0:
//		int x; // uninitialized. Has only a random value
//		int y = 3; // error : declaration can be bypassed (explicitly initialized)
//		std::string s; // error : declaration can be bypassed (implicitly initialized)
//	case 1:
//		++x; //error : use of uninitialized object
//		++y;
//		s = "nasty!";
//	}
//}
/**
 * First off, the decalaion of y and s maybe bypassed if case 1 is executed first. Hence, Wow!
 * Second, x is not initialized, and we're adding to it, even when we start from case 0. Don't do it!
 */

 /**
  * As we said, the declaration of a variable, or in general the = operator is an l value. Hence,
  * an expression like this is allowed, and shortens the scope of the variable
  */
//void e() {
//	if (double d = prim(true)) {
//		left /= d;
//		break;
//	}
//}