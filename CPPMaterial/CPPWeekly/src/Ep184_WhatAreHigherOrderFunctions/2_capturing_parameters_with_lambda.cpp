/**
* As we already know, we can capture particular parameters as we desire with lambdas. In the following example, 
* we invalidate some parameters with move semantics, while capturing other as reference and another one as 
* copy, but we send in the rest of the parameters with reference.
* 
* In other words, when we say [& or =, move a, equate b, etc], we pass all parameters as reference or equal,
* except the rest which we specialize.
*/

#include <string>
#include <iostream>

using std::string;
using std::cout;

void capturing_parameters() {
	string s1 = "abc";
	string s2 = "def";
	string s3 = "ghi";

	// Send all parameters as reference, except for s1 and s2, which we specialize.
	auto lambda = [&, s1 = std::move(s1), s2 = s2](){ 
		cout << "Address of s2 inside is: " << &s2 << " and address of s3 inside is: " << &s3 << '\n';
	};

	cout << "Notice that s1 is invalidated even before calling the lambda: " << s1 << '\n';

	cout << "The address of s2 on the outside is: " << &s2 << " and s3 is: " << &s3 << '\n';
	lambda();
	cout << "Hence, s2 has been copied inside and s3 is passed by reference " << '\n';

}

//int main() {
//	capturing_parameters();
//}