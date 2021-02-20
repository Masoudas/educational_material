/**
* So now that we know that push_back and insert (allegedly, but not in recent versions of the standard)
* first construct the object, and then place it in the buffer (hence two assignments), we shall use emplace
* and emplace_back.
* 
* These two, merge the two operations in one, initializing the memory location with the received object. In
* other words, they don't do (T* t = new T[], t[n] = received_object). Therefore, these methods are much
* faster than insert and push_back.
* 
* Something else about emplace and emplace_back is that we can pass the constructor parameters, instead of
* the actual object. If we actually inspect the emplace_back method, we see that they use variadic arguments
* for this very purpose of passing constructor arguments. 
* 
* If I wanted to think of this in a very chilish manner, the implementation of emplace_back is something like
template<typename...Args>
void emplace_back(Args...args){ T* t = new T[]{ args is expanded here};}
*/

#include <vector>
#include <iostream>

using namespace std;

struct Y {
	int x;
	Y(int x, int y) : x{ x } {}
	Y(Y&& other) noexcept : x{ other.x } { cout << "Using move constructor\n"; }
	Y(const Y& other) : x{ other.x } { cout << "Using copy constructor\n"; }

	Y& operator=(const Y& other) { x = other.x; cout << "Inside copy assignment\n"; return *this; }
	Y& operator=(Y&& other) noexcept { x = other.x; cout << "Inside move assignment\n"; return *this; }
};

void push_back_passing_constructor_args() {
	vector<Y> vec{};

	// vec.push_back(1, 2); Not possible. Although if constructor needed only one parameter, this
	// would have been fine.
}

void emplace_back_passing_constructor_args() {
	vector<Y> vec{};

	vec.emplace_back(1, 2);	// Forwarding of constructor arguments. Note the use of variadic arguments
							// for implementation of method! (Ok ... Cool).
}
