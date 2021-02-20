/**
* As of CPP 20, it's possible to bring an enum into a particular scope with "using". In that sense,
* an enum class will be the same as a plain enum. Although oddly enough, the intellisense says this is
* not possible, however it's possible as of CPP20.
* 
* Note that such declaration allows access to the scope parameters only (apparently). To use the actual
* enum type, we need to include it with a using directive. See example 2.
*
*/
#include <iostream>
using namespace std;

enum struct Days { MONDAY = 1, TUESDAY = 2};

class enum_user {

	using enum Days;

	void f(Days d) {
		switch (d)
		{
		case MONDAY:
			break;
		case TUESDAY:
			break;
		}
	}
};

namespace ns{
	enum struct E {e1 = 1, e2};
}

void using_E() {
	using ns::E;	// This one only declares the type, not the scope values.
	using enum ns::E;	// This one declares values.

	E e = e1;
	if (e == e1) {
		cout << "Yo!";
	}
	else {
		cout << "No!";

	}
}

//int main() {
//	using_E();
//}