/**
* The standard states:
* 
* The Boolean literals are the keywords true and false. They are prvalues of type bool.
* 
* Note that non-zero integer values (char, short, int, ...) are implictly converted to true, and zero is
* converted to false.
* 
* As another side note, we use the boolalpha method to stream bools as true or false. Otherwise, they'd be
* printed as 0 or 1 in booleans.
*/

#include <iostream>

void stream_booleans() {
	std::cout << true << " and " << false << " become : " << std::boolalpha << true << " and " << false;
}

//int main() {
//	stream_booleans();
//}