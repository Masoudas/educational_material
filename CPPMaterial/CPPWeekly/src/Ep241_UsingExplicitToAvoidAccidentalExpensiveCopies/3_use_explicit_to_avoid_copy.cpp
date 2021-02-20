/**
* Essentially, if we make the copy constructor explicit, then based on 2, people can't use as plain function 
* argument. Therefore, copying it would be impossible. Therefore, users of the class would have to pass it 
* only as rvalue, reference, or pointer.
*/
#include <utility>

struct explicit_cp {
	explicit_cp(){}
	explicit explicit_cp(const explicit_cp&) = default;
	explicit_cp(explicit_cp&&) = default;
};

void cant_use_plainly(explicit_cp c) {
	// cant_use_plainly(c); Impossible, needs copy.
	// cant_use_plainly(explicit_cp{});	Impossible. const& is explicit. We can't use move constructor, because
									// we didn't declare we accept rvalue reference!
}

void can_use_move(explicit_cp&& c) {
	can_use_move(std::move(c));	// Fine. move
	can_use_move(explicit_cp{});	// Now we use move!

}

void can_use_reference(explicit_cp& c, explicit_cp* p) {
	can_use_reference(c, p);
}