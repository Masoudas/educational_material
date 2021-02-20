/**
* As we know, when passing an array, a pointer to its initial argument is passed:
* 1-	For T[] array, T* is passed.
* 2-	For T[][n], (*T)[n] is passed.
* ...
* 
*/
#include <iostream>
using namespace std;

/*
* Question: Can we overload a function with pointer and array? The answer is No.
* What about a 2D array? Yes.
*/
void overload_with_p_and_arr(int* p) { cout << "Inside pointer version" << endl; }
// void overload_with_p_and_arr(int p[]) { cout << "Inside array version" << endl; } Impossible.
void overload_with_p_and_arr(int p[][1]) { cout << "Inside 2d-arr version" << endl; }

//int main() {
//	int* ptr = nullptr;
//	int arr[] = { 1, 2, 3 };
//	int arr2[][1] = { {1}, {2} };
//	overload_with_p_and_arr(ptr);
//	overload_with_p_and_arr(arr);
//	overload_with_p_and_arr(arr2);
//}

/*
* We may also pass an array by refernece (more precisely pointer to an array is passed by refernece).
* They are however not that flexible.
*/
void pass_array_pointer_as_ref(int (&arr)[5]) {
	arr[0] = 4;	
}

/**
* One solution would be to pass the size of the array as a template. It's interesting to note
* that under such a definition, we needn't specify the type or size.
*/
template <typename T, int N>
void pass_array_size_as_template_argument(T(&arr)[N]) {
	int arr[] = { 1, 2, 3, 4 };
	pass_array_size_as_template_argument(arr);	// Interesting!
	pass_array_size_as_template_argument<int, 4>(arr); // Though this is also ok.
}

/**
* Finally, note that for multi-dimensional arrays, we can always use array of pointers notion
*/