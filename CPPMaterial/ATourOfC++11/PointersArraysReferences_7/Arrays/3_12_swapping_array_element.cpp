/**
* We shall not forget that a reference points to the underlying variable. Hence we can use the swap
* method of stl to swap two elements of an array.
*/
#include <iostream>
using namespace std;

void swapping_elements_of_array() {
	int* arr = new int[2]{ 1,2 };

	swap(arr[0], arr[1]);	// Takes the reference to these elements.
	//swap(*arr, *(arr+1));	// Swap back!

	cout << arr[0] << '\t' << arr[1];
}

//int main() {
//	swapping_elements_of_array();
//}