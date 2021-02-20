/**
* So here's something interesting to note, which I first found out about when studying unique_ptrs. A class can
* be specialized with a pointer, and a pointer separately. This for example is useful if we want to introduce a
* bracket operator to the game.
*/
#include <iostream>

template <typename T>
struct unique_ptr {
};

template <typename T>
struct unique_ptr<T[]> {
	void operator[](int) {
		std::cout << "Inside T[] specialization of ptr\n";
	}
};

//int main() {
//	unique_ptr<int[]> ptr{};
//	ptr[5];
//
//	unique_ptr<int*> ptr1{};
//	// ptr1[3]; Error! No such operator for ptr1.
//}