/**
* For completeness, I write the meaning of each ordering type from cppreference.com. In one look, we see that
* the difference is whether if a == b implies f(a) = f(b) (strong order), and that one of <, == or >
* holds (strong and weak order).
* 
* 1- weak_ordering: The class type std::weak_ordering is the result type of a three-way comparison that
*	-	admits all six relational operators (==, !=, <, <=, >, >=)
*	-	does not imply substitutability: if a is equivalent to b, f(a) may not be equivalent to f(b), 
*		where f denotes a function that reads only comparison-salient state that is accessible via 
*		the argument's public const members. In other words, equivalent values may be distinguishable.
*	-	does not allow incomparable values: exactly one of a < b, a == b, or a > b must be true
* 
* 2- partial_ordering: 
*	-	admits all six relational operators (==, !=, <, <=, >, >=)
*	-	does not imply substitutability: if a is equivalent to b, f(a) may not be equivalent to f(b), 
*		where f denotes a function that reads only comparison-salient state that is accessible via the 
*		argument's public const members. In other words, equivalent values may be distinguishable.
*	-	admits incomparable values: a < b, a == b, and a > b may all be false
* 
* 3- strong_ordering:
*	-	admits all six relational operators (==, !=, <, <=, >, >=)
*	-	implies substitutability: if a is equivalent to b, f(a) is also equivalent to f(b), where f denotes 
*	-	a function that reads only comparison-salient state that is accessible via the argument's public 
*	-	const members. In other words, equivalent values are indistinguishable.
*	-	does not allow incomparable values: exactly one of a < b, a == b, or a > b must be true
*/