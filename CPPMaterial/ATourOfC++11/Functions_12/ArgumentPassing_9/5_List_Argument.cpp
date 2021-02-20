/**
* As we already know, the notion {1, 2, 3, 4} is an rvalue. Hence, passing it to a
* method that for example accepts a pointer is not possible.
*
* To remedy that situation, we can use initializer_list, which as remember was just a container
* to constant elements.
*
* In conclusion, the list delimiter {} can be used as an argument of:
* 1-	a initializer_list, where the values of the list can be IMPLICITLY converted to T.
* 2-	A type that can be provided with the values provided in the list (me: calls constructors)
* 3-	A reference to an array of T, where the values of the list can be implicitly converted to T
*	(me: Say what now?! Don't we need a const key word here?)
*
* Consider the following examples:
*/
#include <initializer_list>
#include <iostream>
using namespace std;

void this_method_can_be_initialized_with_list(const int(&ref)[5]) {
	// this_method_can_be_initialized_with_list({ 1, 2, 3, 4, 5 }); 
	this_method_can_be_initialized_with_list({ 1, 2, 3, 4, 5 }); // This initialization is impossible without the const
	// this_method_can_be_initialized_with_list({ 1.2, 1.3, 1.4, 1.5, 1.6 }); // My compiler does not allow this
}

// Should we declare this using rvalue ref as well?
template <typename T>
void pass_initializer_list(initializer_list<T> list) {
	// T* arr = list; This is not how we do it.
	T* arr = new T[list.size()];

	int i = 0;
	for (auto var : list)
	{
		arr[i++] = var;
	}
	cout << arr[0] << endl;
}

struct S { int a; };

void passing_struct_initialized_with_bracket(S s) {
	passing_struct_initialized_with_bracket({ 1 });	// This call is still bizzare to me, because we have no such constructor!	
}

//int main() {
//	pass_initializer_list({ 1, 2, 3 });
//}


