/**
* First of the list are lambdas. As we already some what know, lambdas are not function pointers, but
* rather something called a closure. Closure is an unnamed type, and is unique for each closure. Therefore,
* two closure variables which are (supposedly) the same lambdas cannot be assigned to one another.
* 
* To capture a lambda and define it as a variable, we have to use auto.
* 
* There's one point of interest here. We can actually alias a lambda, using the decltype to get its
* type. However, aliasing is not the same as defining a concrete type.
* 
* As a consequence of this fact, if we want to have a function that returns a lambda, we have to use auto
* type reduction.
*/

void lambdas_have_no_type() {
	auto nothing_lambda = [](){};
	auto same_nothing_lambda = [](){};

	// same_nothing_lambda = nothing_lambda; Error! No operator for assigning lambdas to each other.
											// Every declared lambda has a different type.

	// Aliasing a lambda. This is ONLY possible as of C++20, because we have default constructed lambdas.
	using lambda_alias = decltype(nothing_lambda);

	// lambdas can be assigned to function pointers, not vice versa.
	using void_ptr = void (*)();	// No need for decltype! (I haven't figure out when we need decltype!)
	void_ptr lambda_ptr = nothing_lambda;	// Fine, although some people say there should be a plus sign here!
}

// We have to use auto type deduction.
auto generate_addition_lambda(int val){
	return [=](int v)->int{ return v + val; };
}