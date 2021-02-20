/**
* Quick sort is implemented in the algorithms class. It takes as parameter an iterator to the 
* start and end point, which is quite interesting.
* The api of qsort is:
* qsort( void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *) );
* 
* where ptr is the pointer to first element, cound is size of array, size is the size of each element,
* and comp is a function pointer, comparing two elements of the given size.
* 
* There's also a qsort_s(), which also accepts a context parameter. Apparently it's more secure.
* 
* Note: As we can see in the comparison lambda for strings, I had no choice but to use c-style cast. I'm
* sure that somewhere, Bjarne's head has exploded!
* 
* Note however that we prefer sort, which is much faster than qsort, and more specifically, we prefer
* sort_stable(), which keeps the order of equivalent elements.
*/

#include <algorithm>
#include <iostream>
using namespace std;

void using_cpp_quick_sort_with_strings() {
	const char* arr[] = { "How I wonder", "What you are", "ABCDEFG" };
	
	auto compare = [](const void* a, const void* b)->int{
		const char** a1 = (const char**)a;
		const char** b1 = (const char**)b;
		return strcmp(*a1, *b1); };
	qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(char*), compare);

	for (int i = 0; i < 3; i++)
	{
		cout << arr[i] << endl;
	}
}

//int main() {
//	using_cpp_quick_sort_with_strings();
//}