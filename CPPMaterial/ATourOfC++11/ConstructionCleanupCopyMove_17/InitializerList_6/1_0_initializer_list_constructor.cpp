/**
* It's used for passing a list of arguments to construct a class. 
* 
* Standard library containers mostly supply such constructor, and assignments with such
* them.
*/
#include <vector>
#include <iostream>
using namespace std;

void initializer_list_constructors_and_assignment() {
	vector<int> vec{ 1, 2, 3 };
	vec = { 4, 5, 6 };	// The entire vector is reassigned to this list.

	for (auto var : vec)
	{
		cout << var << '\t';
	}
}

//int main() {
//	initializer_list_constructors_and_assignment();
//}