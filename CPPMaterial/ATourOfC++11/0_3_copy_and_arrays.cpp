/**
* Stack arrays are copied if put inside a class. Spcefically, if each element has a copy constructor, that
* constructor is called.
* 
* Of course we know that if there's only a pointer here, only the value of that pointer is copied.
*/
#include <iostream>

struct X {
	X() = default;
	X(const X&) { std::cout << "Inside copy constructor \n"; }
};

struct array_is_copied {
	X arr[2] = { X{}, X{} };
};

//int main() {
//	array_is_copied cp{};
//	array_is_copied s{ cp };
//}