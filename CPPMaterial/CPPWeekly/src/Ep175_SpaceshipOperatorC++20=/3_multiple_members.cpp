/**
* Note that if a class has multiple invariants, the spaceship operator works on each and everyone of them.
* Note that this function appear to be only working for built-in types, and not custom types.
*/
#include <iostream>
#include <compare>

using std::string;

struct Data {
	int i;
	int j;
	//string s;

	auto operator<=>(const Data&) const noexcept = default;
};

void using_Data_threeway_compare() {
	Data d1{ 1, 1 };
	Data d2{ 1, 1 };	// Lexicographically greater than d1

	if (d2 >= d1) std::cout << "d2 is greater than equal to d1";
}

//int main() {
//	using_Data_threeway_compare();
//}