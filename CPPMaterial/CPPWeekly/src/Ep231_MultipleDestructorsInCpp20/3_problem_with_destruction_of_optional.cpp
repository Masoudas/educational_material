/**
* Based on the discussions we've had thus far, it's clear that the optional we created in 2 has the problem
* that the compiler deletes the destructor, because of what we mentioned in 0_2. 
* 
* We may naively try to implement the destructor as follows, but we can't be sure of the type of object
* the optional holds. Hence, if a built-in type is supplied, the optional fails.
* 
* Again, note how the destructor of t is called!
*/

template<typename T>
struct optional {
private:
	union {
		char dummy = 1;
		T t;
	};

	bool has_value = false;

public:
	optional& operator=(T t) {
		t = t;

		return *this;
	}

	T get() {
		if (!has_value) throw "exception";

		return t;
	}

	~optional() {
		if (has_value) {
			t.~T();	// What if the type is built-in?
		}
	}
};