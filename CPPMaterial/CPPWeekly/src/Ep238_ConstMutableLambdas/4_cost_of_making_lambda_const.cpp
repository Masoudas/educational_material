/**
* There's however a cost associated with making a lambda const, which is that if we also decalre the lambda
* mutable, then an error might occur.
* 
* The error occurs, because declaring a lambda mutable implies that we can change it's defined values. However,
* const says the lambda internal values (or as we now know, the class values) should not change. This would lead
* to a contradiction, which can be resolved by either removing the const or the mutable keyword!
* 
* Notice that even though the definition of const mutable class is Ok, when we try to use it, we're trying to
* access a non-const method of a const variable (only methods appended with const must be called with const
* values), which is why we get an error when we try to use the lambda.
*/

void const_mutable_lambda() {
	int s{}, s1{};
	// const auto lambda = [i = 0, &s, s1](){ return i++; }; Error! Changing parameters of a const class
	const auto lambda = [i = 0, &s, s1]() mutable { return i++; }; 

	// lambda(); Error!

	auto lambda1 = [i = 0, &s, s1]() mutable { return i++; }; // Fine!

}