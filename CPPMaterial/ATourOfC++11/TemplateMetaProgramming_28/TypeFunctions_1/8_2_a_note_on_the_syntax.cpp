/**
* Note the parentheses around sizeof(int)>5 in the previous example, as in:
	
	conditional<(sizeof(int) > 4), ...>

* Without those, we would have gotten a syntax error because the compiler would have interpreted the > as the end
* of the template argument list (me: so it would have been conditional_t<sizeof(int)> 4, which is an error). For that 
* reason (and others), I prefer to use < (less than) rather than > (greater than). Also, I sometimes use parentheses 
* around conditions for readability.
*/ 