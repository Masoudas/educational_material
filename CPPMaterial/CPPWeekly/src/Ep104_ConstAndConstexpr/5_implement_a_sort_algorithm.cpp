/**
* Here's a question: Can I implement a constexpr sort algorithm?
* 
* Answer: Note that theoretically, the method can be constexpr. However, if we get an array (in particular
* a literal pointer) at compile-time, that array is constant. Therefore, we can't change its elements, and 
* swap them. Therefore, we can't implement such a sort algorithm to sort at compile time.
* 
* Can we implement a max method for example? Not in a traditional sense. Because we need to define a value
* called max. This value however changes as we traverse the array, which makes it impossible for it to be
* a constexpr value. This is in spite of the fact that we can use for loops. The point is that the data
* has to change.
* 
* Now, we may think of something like the following. We use a recursive function to go from the back of the
* array and calculate the max. Note that we have no variable changing value. In fact, just to stress this,
* I've made everything const. The addition and subtraction calculations are fine, and can be done at compile
* time. Again, note that recursion is so C++11. A for loop is possible since C++14, which we use to initialize
* our array. 

* A constexpr array can be initialized inside a class, which we can see below. But once initialized, it can't
* be modified.
* 
* In conclusion, we can perfrom operations on constexpr data that return some feature of the data 
* (min, max, median, ...), but we can't change a constexpr data (because after all, it's a constant data).
*/
#include <array>
#include <iostream>
using std::array;

constexpr int max(const int* v1, const int m, const int index) {
	if (index < 0) return m;
	
	if (v1[index] > m) return max(v1, v1[index], index - 1);
	else return max(v1, m, index - 1);
}

constexpr int get_max(const int* const v1, const int size) {
	if (size == 1) { return v1[0]; }

	return max(v1, v1[size - 1], size - 2);
}

constexpr array<int, 4> arr{ 1, 5, 3, 4 };
constexpr int arr1[4] = { 1, 5, 3, 4 };

constexpr int arr_max = get_max(&arr[0], 4);
constexpr int arr1_max = get_max(&arr1[0], 4);

//int main() {
//	std::cout << arr_max;
//}