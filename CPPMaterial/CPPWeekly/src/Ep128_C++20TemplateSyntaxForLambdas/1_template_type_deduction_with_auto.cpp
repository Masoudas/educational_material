/**
* A feature that was added in C++14 was that we could deduce the type of each argument together with the
* return type using auto.
*/

void auto_lambda_argument_deduction() {
	auto lambda = [](auto left, auto right)->auto{ return left + right; };

	auto result = lambda(1, 2);	// int<-(int, int)

	auto result1 = lambda(1, 2.2);	// double<-(int, double)

}