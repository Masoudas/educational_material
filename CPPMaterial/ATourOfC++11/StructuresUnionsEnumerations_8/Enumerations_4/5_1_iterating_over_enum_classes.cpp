/**
* We can iterate over an enum class the same way we do with plain enums.
* Trouble is, we need more cast!
*/
#include <iostream>

using namespace std;

enum class Months {
	January = 1, Feburary, March, April
};

Months& operator++(Months& m) {
	m = static_cast<Months>(static_cast<int>(m) + 1);
	return m;
}

void using_months() {
	Months m{};	// Again, don't forget that this initializes to zero!
	for (; m  <= Months::April; ++m)
	{
		cout << static_cast<int>(m) << '\t';
	}
}

//int main() {
//	using_months();
//}