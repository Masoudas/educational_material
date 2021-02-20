/*
* As we know, arrays of references is not possible in C++. Hence, a collection shall only use
* pointers
*/
#include <vector>
#include <string>
using namespace std;

void collections_only_use_pointers() {
	int* arr = new int[4]{ 1, 2, 3, 4 };

	// int& arr[] = { 1, 2, 3, 4 }; This is not possible.
	int x = 10, y = 20;
	// vector<string&> s1 = { x , y }; // error : vector of references
	vector<string*> s2 = { &x, &y }; // OK
}

