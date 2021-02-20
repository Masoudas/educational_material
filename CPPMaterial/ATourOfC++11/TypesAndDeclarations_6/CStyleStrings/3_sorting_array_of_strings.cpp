/*
* Sorting an array of strings is less challenging, as we can use the pointer to the 
* first and last element of the array, without having to modify each individual string. The problem
* is that sort uses < for the strings, however, there's no such comparison for c-style strings.
* Therefore, we need to provide a predicate for sort. Note that the predicate returns a bool,
* and not an int.
* 
* With qsort however, pay speciall attention to how we need to use c-style cast. Recall that each
* element of an array of c-style strings is a pointer to pointer of char. We can't use static
* cast, because it won't allow us to cast a pointer to double pointer (it doesn't allow type change).
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void sort_array_of_cstyle_strings_with_sort() {
	const char* arr[] = { "How I wonder", "What you are", "ABCDEFG" };
	
	auto predicate = [](const char* a, const char* b)-> bool {
		return strcmp(a, b) <= 0; };
	// sort(arr, arr + 3);	wrong
	sort(arr, arr + 3, predicate);


	for (auto c_string_ptr : arr) {
		cout << c_string_ptr << endl;
	}
}

void sort_array_of_cstyle_strings_with_qsort() {
	const char* arr[] = { "How I wonder", "What you are", "ABCDEFG" };

	auto comparison = [](const void* a, const void* b)-> int {
		return strcmp( *(const char**)a, *(const char**)b); };
	// sort(arr, arr + 3);	wrong
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(const char*), comparison);


	for (auto c_string_ptr : arr) {
		cout << c_string_ptr << endl;
	}
}

//int main() {
//	sort_array_of_cstyle_strings_with_sort();
//	sort_array_of_cstyle_strings_with_qsort();
//}
