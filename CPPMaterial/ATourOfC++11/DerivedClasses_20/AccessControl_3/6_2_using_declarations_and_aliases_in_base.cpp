/**
* Question: Are public alias and using declarations inherited? If we conside that a class is a namespace, we know
* that a namespace can inherit every property of the base (by dragging the other namespace with the using
* declaration). In conclusion, yes. A public inheritance for example inherits the declaration and alises of the
* base.
*/
#include <vector>

class base {
public:
	using uint = unsigned int;
	using vec = std::vector<int>;
};

class derived : public base{
public:
	vec f(){}	// vec is available as part of the base class definition.
};

void further_proof_using_statements_being_available() {
	derived::uint val{ 5 };
}