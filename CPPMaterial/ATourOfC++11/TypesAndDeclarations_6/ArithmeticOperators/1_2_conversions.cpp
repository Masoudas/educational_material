/**
* If the operand passed to an arithmetic operator is integral or unscoped enumeration type, then before any 
* other action (but after lvalue-to-rvalue conversion, if applicable), the operand undergoes integral 
* promotion. If an operand has array or function type, array-to-pointer and function-to-pointer conversions 
* are applied.
* 
* For the binary operators (except shifts), if the promoted operands have different types, additional set of 
* implicit conversions is applied, known as usual arithmetic conversions with the goal to produce the common 
* type (also accessible via the std::common_type type trait). If, prior to any integral promotion, one 
* operand is of enumeration type and the other operand is of a floating-point type or a different enumeration 
* type, this behavior is deprecated. (since C++20)
* 
* If either operand has scoped enumeration type, no conversion is performed: the other operand and the return 
* type must have the same type.
* 
* Me: What does this mean? Let's just for argument's sake note that we can't possibly have enums of greater
* than int. We see that all our normal operations which we normally see done on enums as bit fields end up
* in enum. Then, we know that a comparison is always possible because enums (of at most int) can be implicitly
* converted to ints. Note however that this is for unscoped enums (ones without enum class.) For enum classes,
* we don't have any implicit conversion to integral types, and we need explicit conversions.
* 
*/

namespace enums {

	enum c_enum : char { a, b };
	enum i_enum : int { c, d };

	void ops_on_enums() {
		auto c_result1 = c_enum::a | c_enum::b;	
		auto c_result2 = c_enum::a + 1;

		switch (c_result1) {
		case c_enum::a:
			return;
		case c_enum::b:
			return;
		}
	}

}