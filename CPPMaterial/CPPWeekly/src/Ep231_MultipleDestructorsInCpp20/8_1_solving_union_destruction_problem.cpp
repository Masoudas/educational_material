/*
* We can solve the problem optional union destruction by checking whether the type is trivially destructible
* or not. We can then call the destructor accordingly. We're gonna do this C++11 and C++20 style.
* 
* Question: What's wrong with the following solution? It seems to work just fine!
*/

#include <type_traits>
#include <string>
#include <iostream>

struct S {
	~S() {
		std::cout << "Destructed";
	}
};
template<typename T>
struct optional {
private:
	union {
		char dummy;
		T t;
	};

	bool has_value = false;

public:
	optional() : dummy{ 1 }, has_value{ false } {}

	optional& operator=(T&& t) {
		t = std::move(t);

		return *this;
	}

	T get() {
		if (!has_value) throw "exception";

		return t;
	}

	~optional() {
		if (has_value && std::is_trivially_destructible_v<T>) {
			t.~T();
		}
	}
};

//int main() {
//	optional<S> op{};
//	op = S{};
//
//	optional<int> op1{};
//	op1 = 1;
//
//
//}