/*
* So here's a question. What happens when I assign to an array with a reference?
* 
* Note that an array is a block of memory. When an array is initialized, every element of it 
* is initialized with its own memory, using a constructor of the type. Hence, a[n] = t is an
* assignment operator, not reassigning a memory address! Meaning the address of a[n] and t would
* not be the same after (even though their content might be due to nature of assignment operator).
* So, with that introduction:
* 
*		Built-in types: It will be like saying int x = y, where y is an int reference. So a 
* new copy is created in the array memory location.
*
*		User defined types: This assignment calls the assignment operator of course. 
* So whatever happens inside that operator, is the result. For example, for strings, 
* an assignment operator makes a new copy of the string. Thus, we actually make a 
* new copy in the array location, rather sharing resources. However, we may share 
* resources for other types.
* 
* (Me: The whole point is that perhaps one reason containers don't get objects by reference
* is that they don't want to create a binding with the outside object. They either accept a 
* copy, or an rvalue reference, I think!)
* 
* 
*/
#include <iostream>
using namespace std;

struct a_struct {
	string s = "";
	a_struct() { cout << "Inside default constructor" << endl; }
	a_struct(const a_struct& ref) { cout << "Inside copy constructor" << endl; }

	a_struct& operator=(const a_struct& ref) { cout << "Inside assignemnt operator" << endl;
		this->s = ref.s;
		return *this;
	}

	~a_struct() { cout << "Inside destructor operator" << endl; }
};

void assigning_to_an_array_with_reference() {
	string arr[3] = {};	// Initializing array with default constructor.
	string* str1 = new string{ "Str" };
	string& str2 = *str1;

	arr[0] = str2;
	
	cout << "Note that object address is: " << &str1 << " but array address is " << arr << endl;

	delete str1;
	cout << "str2 is going out of scope here. But assignment operator creates an independent copy" << endl;
	cout << "We still print Str: " << arr[0] << endl;
}

void assigning_to_custom_array_with_reference() {
	a_struct arr[1] = {};	// Initializing array with default constructor. An string is inside each one
	a_struct* str1 = new a_struct{ };
	a_struct& str2 = *str1;

	arr[0] = str2; // The memory is now shared between two objects inside arr[0] and str2. 
				   // However, their internal string assignment creates independent copies.
					// So I can just go ahead and delete them independently!
	delete str1;
	cout << "Array going out of scope, hence calls the destructor on each of its elements" << endl;
}

//int main() {
//	assigning_to_an_array_with_reference();
//	assigning_to_custom_array_with_reference();
//}

