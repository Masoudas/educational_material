/**
* Even if an in class initializer is declared, we can then again declare member initalizers. The member
* initializers will take precedence over in class initializers.
*/

#include <iostream>
using namespace std;

struct my_struct {
	const int i = 10;

	my_struct() : i(20) {}
};

void using_overriden_in_class_initializer() {
	my_struct s1{};

	cout << "value is set to overriden member initializer, even for a const: " << s1.i << endl;
}

//int main() {
//	using_overriden_in_class_initializer();
//}