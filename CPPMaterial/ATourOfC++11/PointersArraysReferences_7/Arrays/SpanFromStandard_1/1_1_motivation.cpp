/**
* Me: From what I've gathered, a span is supposed to be like an string_view container for a C-String. That is,
* a thin wrapper over the normal c-style array, which would allow working with the underlying array, albeit in a 
* an intrusive manner as opposed to a normal string (for which an string_view is non-intrusive and read only.)
* Note that for this wrapper to work, the underlying container has to be a CONTIGUOUS section of memory.
* 
* It's possible to assign a static or a dynamic array to this container, which is introduced in C++20. After
* that, we get the normal functions of a container such as front, back, operator[], iterator, etc.
* 
* Notice that for the static array, we can access the array size at compile time through a parameter called
* extent.
* 
* As we can see, the purpose of span is greater than just a wrappper for c-style arrays, and it can also wrap
* a vector, which is good. But it can't encompass a list for example, because that one isn't contiguous in
* memory.
*/

#include <span>
#include <array>
#include <vector>
#include <iostream>

void span_on_a_static_array() {
	using std::span;
	int arr[5] = { 1, 2, 3, 4, 5 };

	span<int, 5> wrapper{ arr };
	// span<int> wrapper{arr};	Fine too, to make array access uniform.

	std::cout << "The size of the array is: " << wrapper.extent << " or equivalently " << wrapper.size() ;

	wrapper[4] = 42;

	for (auto rbegin = wrapper.rbegin(); rbegin != wrapper.rend(); ++rbegin) {
		// Playing with the content with an iterator
	}
}

void span_on_array() {
	using std::span;
	std::array<int, 3> arr{1, 2, 3};
	
	span<int, sizeof(arr) / sizeof(arr[0])> wrapper{ arr };	// Directly accepts an array in constructor.
}

void span_on_a_dynamic_c_array() {
	using std::span;
	int* arr = new int[5];	// Uninitialized memory as we recall.

	// span<int, 5> wrapper{ arr }; // Error, not a dynamic array
	span<int> wrapper{ arr, arr + 5 };	// Wraps a dynamic array using begin an end.

	std::cout << "The size of the array is: " << wrapper.size() ;
}

void span_on_a_vector() {
	using std::span;

	std::vector v{ 1, 2, 3, 4 };	// Using class template deduction on vector
	span<int> wrapper{ v };	// Interesting that there's a direct converter for vector! Of course it exists,
							// because we can read the size of it and everything.
}


