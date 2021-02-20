/**
* Feast your eyes on the following example and never forget that templates are part of function
* signature. This does make sense, because in C++, a template could be a built in type (like for
* example asking for an int as template). Hence, template needs to become part of function signature.
* 
* In fact, Bjarne says: "If a template argument cannot be deduced from the function arguments, 
* we must specify it explicitly"
*/
#include <iostream>
using namespace std;

template<typename T, typename U>
void method_overload_with_templates() {
	cout << "Inside method with two templates" << endl;
}

template<typename T>
void method_overload_with_templates() {
	cout << "Inside method with one template" << endl;
}

//int main() {
//	method_overload_with_templates<int, int>();
//	method_overload_with_templates<int>();
//}