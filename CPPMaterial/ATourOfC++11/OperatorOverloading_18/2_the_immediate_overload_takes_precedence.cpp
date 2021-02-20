/**
* Recall that an immediate operator overload takes place over ADL.
*/
#include <string>
#include <iostream>

std::ostream& operator<<(std::ostream& o, const char* str) {
	std::string message = "We're inside my operator, so the message is never printed!";
	o << message;
	
	// Note that if I had written o << "We're inside my operator, so the message is never printed!",
	// I'd have gotten an stack overflow (I know why, do you?)

	return o;
}

//int main() {
//	std::cout << "Doesn't matter what is here";
//}