/**
* Now, if we're dealing with compile time logic, we can also use constexpr if conditions. An example is
* given below, where we check for double at least 4 bytes.
*/

struct Type {
	int data{};

	constexpr int do_thing() const { return data + 4; }	// Only a return statement, per C++11.
	constexpr int do_another_thing() const { return data + 4; }	// Only a return statement, per C++11.
};

constexpr void constexpr_conditional() {
	constexpr Type t{};
	if constexpr (sizeof(double) > 4) {
		t.do_thing();
	}
	else {
		t.do_another_thing();
	}
}
