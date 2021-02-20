/**
* We can use requires, and at the same type overload the destructor! 
* 
* Yes, as of C++20, we can overload the destructor. Notice how we don't repeat the required for the default
* constructor!
*/
#include <type_traits>

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

	~optional() requires(!std::is_trivially_destructible_v<T>) {
		if (has_value) {
			t.~T();
		}
	}

	~optional() = default;
};