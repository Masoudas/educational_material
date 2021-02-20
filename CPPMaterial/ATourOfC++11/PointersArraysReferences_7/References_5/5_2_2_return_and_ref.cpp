/**
* Suppose a class has a move and copy constructor, and an assignment overload. Then a return would use which one?
* If the type has a move constructor and the value is created inside the method, then the move constructor is used.
* Otherwise, it uses the copy constructor.
* 
* Note also that the empty bracket {} is an rvalue (equivalent to A{}). When passed to a function
* directly, the compiler neither uses copy, nor assignment, nor move, when creating the rvalue ref argument.
*/
#include <iostream>
using namespace std;

class A {
public:
	A() {};
	A(const A& ref) { cout << "Inside copy constructor" << endl;  }
	A(A&& ref) noexcept { cout << "Inside move constructor" << endl; }
	void operator=(const A& ref) {
		cout << "Inside assignment operator" << endl;
	}

	void operator=(A&& ref) noexcept {
		cout << "Inside rvalue assignment operator" << endl;
	}
};

/* Here a copy is made from object. Upon return however, the compiler uses move semantics to salvage a copy.*/
A get_an_object_return_an_object(A a) {
	cout << "get_an_object_return_an_object" << endl;
	return a;
}

/* When passing a reference, the actual object is passed. Hence, no move or assignment takes place.
When returning, a copy takes place, because move would destroy the passed object, and assignment changes
the object from return!*/
A get_reference_return_an_object(A& a) {
	cout << "inside get_reference_return_an_object" << endl;
	return a;
}

/* A copy takes place when passing the argument. However, nothing takes place during return, because
we're returning the copy. It's interesting that VS throws no warning here, because copy is on stack,
hence, it will be destroyed after a while. Perhaps the compiler optimizes this case for us! But we know for a
fact that if the object were made on the stack (an auto object), it would have shown a warning.*/
A& get_an_object_return_reference(A a) {
	cout << "inside get_an_object_return_reference" << endl;
	return a;
}

/* If move semantic is used, the object is moved here. When returning, the object is once again moved. */
A pass_rvalue_reference(A&& ref) {
	cout << "Inside pass_rvalue_reference" << endl;

	return ref;
}

void testing_different_assignment_operations() {
	A a{};
	get_an_object_return_an_object(a);

	cout << "-------------------------------" << endl;
	get_an_object_return_an_object({});

	cout << "-------------------------------" << endl;
	get_reference_return_an_object(a);

	cout << "-------------------------------" << endl;
	pass_rvalue_reference(move(a));	// We don't destroy the object. We don't also create here. But what do we use to pass?

	cout << "-------------------------------" << endl;
	a = get_an_object_return_an_object(a);

	cout << "-------------------------------" << endl;
	get_an_object_return_reference(a);
}

//int main() {
//	testing_different_assignment_operations();
//}
