/**
* References and consts must be initialized. Recall that the initialization of class parameters can
* be delayed until construction, if a class has such variables, they must either be initialized by
* constructor, or initialized directly. In either case, they have to be initialized.
* 
* Note that because member initialization occurs before executing the constructor body, we need to
* initialize such variables before executing the constructor body, as shown below.
*/
struct with_const_ref_no_constructor {
	const int x = 10;
	const int& y = 10;
};

struct with_const_ref_with_constructor {
	const int x;
	const int& y;

	with_const_ref_with_constructor(): x(10), y(20) {
		// x = 10; Not here, but rather using x() notation.
		// y = 20;
	}
};

//int main() {
//
//}