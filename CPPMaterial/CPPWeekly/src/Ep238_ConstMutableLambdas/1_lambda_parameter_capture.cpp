/**
* As we're aware, a lambda can capture the parameters of the scope in which it's defined. We can pass them
* using = (which means equal), or using & (means take a reference), or even specify particular parameters
* and how they should be caught. 
* 
* It's also possible to define parameters in capture. This is mostly used for generator function lambdas. If
* we decide to define a parameter, we shouldn't specify a type. The type must be left to be automatically 
* deduced.
*/
#include <string>

void capturing_scope_parameters() {
	using std::string;

	string s1{}, s2{};
	int j{};
	auto lambda = [s1, &s2, i = string{}, &j](){
		s2 = "Mama";
		j = 10;// Can't do this!
		// i = 20;	Can't do this either!
	};

	lambda();
}

int main() {
	capturing_scope_parameters();
}