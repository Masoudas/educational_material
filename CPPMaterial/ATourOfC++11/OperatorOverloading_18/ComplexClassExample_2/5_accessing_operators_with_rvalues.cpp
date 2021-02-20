/**
* I think this is an important that need to be emphasized one more time. We can indeed access a an operator (or any other
* operator of a class), with rvalues.
* 
* Does it depend on which version of the operator is overloaded? Not really. For example, with the following complex operator,
* when we summon the operator +, the copy constructor is called with the rvalue reference, and we're fine.
*/

struct complex1{};

complex1 operator+(complex1 lhs, complex1 rhs) { return {}; }

void using_operator_plus_with_r_values() {
	auto r = complex1{} + complex1{};	// Fine!
}