/** This is me:
* So note that a constexpr function just indicates that the function can be evaluated at compile time. It DOES NOT
* imply that the return value of the function is const, unless we again use that return value in compile-time.
* 
* I want to make the distinction between the following two absolutely clear then:
* const int& f()
* constexpr int& f()
* 
* Note that the second one returns a const ref, meaning the return value of the function can't be modified, 
* whereas the second one says this function can be used in compile time. 
* 
* Why do I say this? Consider the tuple<int, int>. There's a method called get for accessing the each element of
* tuple, with signature 'constexpr int& get<int,U>(tuple)'. The point here is that this method is constexpr, but we
* can still change the content of the tuple. The tuple is not immutable!
*/

#include <tuple>
#include <iostream>

void changing_tuple() {
	auto t = std::make_tuple(1, 1);	// Makes an (int, int) tuple

	++std::get<0>(t);	// This is totally fine. The method signature is constexpr, and not const!
	
	std::cout << "The first element of the tuple now is 2: " << std::get<0>(t);
}

//int main() {
//	changing_tuple();
//}