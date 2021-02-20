/**
* You'd be surprised to know that unions actually have a very good use in C++, namely, for creating 
* optionals!
* 
* Why would it be useful to use a union here?  
*/
#include <string>
#include <iostream>

template<typename T>
struct optional {
private:
	union {
		char dummy;
		T t;
	};

	bool has_value = false;

public:
	optional() : dummy{1}, has_value{ false } {}

	optional& operator=(T t) {
		t = t;

		return *this;
	}

	T get() {
		if (!has_value) throw "exception";

		return t;
	}
};
