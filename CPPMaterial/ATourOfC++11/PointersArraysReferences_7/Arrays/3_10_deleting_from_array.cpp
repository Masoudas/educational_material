/*
* So here's a question. Imagine I allocate a generic array (on heap or stack). So I have T* arr.
* Now suppose I want to remove an item from the array. What do I do? 
* 
* So note that an array is the address to some locations in memory. The object is therefore placed
* ONLY in that part of the memory. Hence, if I want to delete that object, I should call its 
* destructor! I must not try and delete the memory address, because that would free the memory,
* hence, cutting the array.
* 
* Another option would be to move the object, then call the destructor on the array element.
* 
* Also note that array class in stl actually copies our object, which is a surprise!
* 
*/
#include <array>
#include <string>
#include <iostream>

using namespace std;

void remove_from_array() {
	array<string, 5> arr{};
	string s1 = "Hey Hey Hey";
	arr[0] = s1;

	// Imagine saying s1~(). Then the element in the array is pointing to a destructed object. So be cautious!
	string s2 = move(arr[0]);	// Moving the element out of arr 1. Now s1 is also empty.
	
	cout << "arr[0] is empty: " << arr[0] << endl;
	cout << "s1 is not empty, because array does not take a reference to our element: " << s1 << endl;

	cout << "s2 is the only holder of the string: " << s2 << endl;
}

//int main() {
//	remove_from_array();
//}