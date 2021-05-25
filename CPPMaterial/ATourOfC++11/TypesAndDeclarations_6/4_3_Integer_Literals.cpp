/**
* According to cpp reference, integer literals come in four flavor:
* 1-	Decimal: Base 10. A nonzero digit followed by digits.
* 2-	Octal: Starting with 0 and followed by 1 to 7.
* 3-	Hexadecimal: Starting with 0x followed by 0 to F.
* 4-	Binary: Starting with 0bm followed by one.
* 
* Then, there's the suffixes, that if provided, may contain one or both of the following (if both are 
* provided, they may appear in any order:)
*	-	unsigned-suffix (the character u or the character U)
*	-	one of
*		-	long-suffix (the character l or the character L)
*		-	long-long-suffix (the character sequence ll or the character sequence LL)
*		-	size-suffix (the character z or the character Z) (since C++23)
* Optional single quotes (') may be inserted between the digits as a separator. They are ignored by the 
* compiler.
*	
* Note: Consider the following initializations:

unsigned long long l1 = 18446744073709550592ull; // C++11
unsigned long long l2 = 18'446'744'073'709'550'592llu; // C++14
unsigned long long l3 = 1844'6744'0737'0955'0592uLL; // C++14
unsigned long long l4 = 184467'440737'0'95505'92LLU; // C++14

* Me: A common mistake would be to initialize with such a large value without putting the ull after it. In
* this way, we may have truncation, because such value would only be long long it.
* 
* Me: According to the standard table, there's a distinction between decimal literals, and non decimal (hex,
* octal and binary.) For the former, unless we explicitly indicate we want unsigned, an unsigned version is
* never considered. Whereas with the latter, first we consider the signed version for the literal, then the
* unsigned version.
* 
* So, with DECIMALS, we know that the literal must not lose its meaning, so the compiler choses the smallest
* type that fits the literal. It DOES NOT USE unsigned types for literals. Hence, u.
* 
* In that sense, we can summarize the rules simply as follows:
* Decimals:
*	-	Has no U or u:
*		-	No suffix (the most used case:)
*			int, long int, long long int
*		-	Has suffix:
*			Start from that suffix and go up.
*	-	Has u suffix:
*		-	Start from signed version and go up.
* Non decimal:
*	-	No suffix:
*		From int, then unsigned version, then go up.
*	-	Add suffix:
*		From suffix go up. Start from unsigned int for no other suffix than u.
* 
* Note that we're talking about the type of the literal here. When the literal is assigned to something, then
* we should consider the cast from the literal to that type.
* 
* Note that for z, we have a signed version for size_t for decimals as well!
* 
* Note that There are no negative integer literals. Expressions such as -1 apply the unary minus operator to 
* the value represented by the literal, which may involve implicit type conversions.
*  

auto x = 12;	// int
auto x = 12u;	// unsigned int
auto x = 1213232142434135154542u;	// unsigned lon long int or overflow
auto x = 3123123123131321lu;	// unsigned long or unsigned long long if not fit.
auto x = 0x1231231231232131;	// from int to unsigned int, then long, and up. This one fits in long long.
auto x = 0x123123213123123u;	// unsigned long long

* Finally, I wish I could remember these out of the box!
*/
void non_decimal() {
	//long x = -0xFFFFFFFF;
}