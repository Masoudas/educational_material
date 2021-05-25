/**
* Summary: Everthing below int is converted to int. This like there's no operator+(short, short), but rather
* operator+(int, int). Signed and unsigned short or char are converted to int if values can be held. Otherwise,
* to unsigned. There's no promotion when for example two ints are multiplied (even if they overflow!)
* 
* prvalues of small integral types (such as char) may be converted to prvalues of larger integral types (such 
* as int). In particular, arithmetic operators do not accept types smaller than int as arguments, and integral 
* promotions are automatically applied after lvalue-to-rvalue conversion, if applicable. This conversion 
* always preserves the value.
*
* The following implicit conversions are classified as integral promotions:
*	-	signed char or signed short can be converted to int;
*	-	unsigned char, char8_t (since C++20) or unsigned short can be converted to int if it can hold its 
*		entire value range, and unsigned int otherwise;
*	-	char can be converted to int or unsigned int depending on the underlying type: signed char or 
*		unsigned char (see above);
*	-	wchar_t, char16_t, and char32_t (since C++11) can be converted to the first type from the following 
*		list able to hold their entire value range: int, unsigned int, long, unsigned long, long long, 
*		unsigned long long (since C++11);
*	-	an unscoped enumeration type whose underlying type is not fixed can be converted to the first type 
*		from the following list able to hold their entire value range: int, unsigned int, long, unsigned long, 
*		long long, or unsigned long long, extended integer types with higher conversion rank (in rank order, 
*		signed given preference over unsigned) (since C++11). If the value range is greater, no integral 
*		promotions apply;
*	-	an unscoped enumeration type whose underlying type is fixed can be converted to its underlying type, 
*		and, if the underlying type is also subject to integral promotion, to the promoted underlying type. 
*		Conversion to the unpromoted underlying type is better for the purposes of overload resolution;
*		(since C++11)
*	-	a bit field type can be converted to int if it can represent entire value range of the bit field, 
*		otherwise to unsigned int if it can represent entire value range of the bit field, otherwise no 
*		integral promotions apply;
*	-	the type bool can be converted to int with the value false becoming ​0​ and true becoming 1.
*		Note that all other conversions are not promotions; for example, overload resolution chooses char -> 
*		int (promotion) over char -> short (conversion).
*/

#include <numeric>
// From me:
void promotion_from_under_int() {
	char c = 'c';
	auto int_now = c + 'c';	// Now int

	// Reminder: Increment operators don't convert! That's because they don't return!

	auto c_not_int = ++c; auto post = c++;	

	short s = 'c';	// Wanted to throw this curve ball. Note that 'c' is indeed an int value after all.
	auto s_int_now = s + s;

	auto no_promotion_to_long = 2 * std::numeric_limits<int>::max();	// No promotion. Only overflow here!
	
}

// This example is from me:
void switch_promition_to_int() {
	char c = 10;
	switch (c) {	// Promotion to int
	case 10:	// Recall that cases must always be const.
		return;
	case 'c':	// Promotion to int.
		return;
	}

	enum x {e, a};
	x w = e;
	switch (w)	// Convesion to int. No promotion is required
	{
	case e:
		break;
	case a:
		break;
	}

	int* d;
//	switch (d) {	// Nope! Because even though d is convertible to bool, no second conversion! No double
					// conversions in C++ so far!
					
}