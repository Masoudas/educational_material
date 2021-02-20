/**
* According to cpp reference, integer literals come in four flavor:
* 1-	Decimal: Base 10.
* 2-	Octal: Starting with 0 and followed by 1 to 7.
* 3-	Hexadecimal: Starting with 0x followed by 0 to F.
* 4-	Binary: Starting with 0bm followed by one.
* 
* As we know, we can have two suffixes, namely L and U.
* 
* So, with DECIMALS, we know that the literal must not lose its meaning, so the compiler choses the smallest
* type that fits the literal. It DOES NOT USE unsigned types for literals.
* IF DECIMAL is followd ONLY by U, one of the unsigned types is chosen. The same goes if U is combined 
* with L.
* If DECIMAL is declared with L, the rules are crazy. We go from long, to unsigned long, to long long. There's no
* unsigned long long here! This is the only crazy rule.
* If LL is suffixed with DECIMAL, we use long long.
* 
* With other types, the rules are very simple. If there's no U suffix, the type alternated between signed
* and unsigned. So int, unsigned int, long, unsigned long, ...
* If there's U, then only unsigned types are used. If there's L, we start from long and alternate. If there's
* LL, from long long.
* 
* Question: What happens when I negate 0xFFFFFFFF in a 32 bit system and assign it to a long? 
* Answer: -1 is promoted to unsigned, then multiplied. Yet, VS does not allow me to test this!
* 
*/
void non_decimal() {
	//long x = -0xFFFFFFFF;
}