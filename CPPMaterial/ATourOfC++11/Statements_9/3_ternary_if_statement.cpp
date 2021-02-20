/**
* This is relatively common knowledge by now, but it should be mentioned. A ternary if can return two different
* types, so long as they have a common type. Therefore, for example, a ternary if can return base*:derived* or
* long:int, where the common type is base* and long, as the following examples demonstrate.
*/

struct base {};
struct derived : base {};

void ternary_if_statement_can_return_different_types(int x, int y) {
	auto result_long = x < y ? 10L : 10;	// We see that result_long is long in this case.

	auto ptr_base = x < y ? new base{} : new derived{};	// We see that ptr_base is a pointer to based in this case.

}