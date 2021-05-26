/**
* Recall that when a pointer goes out of scope, it's corresponding object is not destroyed until we delete
* it (destruct it, then removing the allocated memory.)
* 
* In that spirit, assume that we create an array of pointers on stack. when we create an array of pointers to 
* something, the memory is not freed until we actually delete each pointer individually, to delete the object 
* directed by it. Then, we need to delete the array  itself, to get rid of the array itself. In other words,
* the delete[] operator only removes THIS array from the memory, not the objects pointed to by it. This why,
* if we want to create an array of objects, we always use some kind of smart pointer. Particularly, with
* vectors, recall that because we allocate on heap, we need to use smart pointers.
* 
* Essentially, recall our motto "Always create an array <vector> of smart pointers, not an array of pointers!"
* 
* Why is this important? Because normally, if we want to create an array of base objects, we use pointers to
* avoid slicing.
*/

#include <vector>
#include <memory>
#include <algorithm>

void dynamic_array_of_pointers() {
	int** arr_b = new int* [2]{ new int{1}, new int{2} };	//
	// int* arr_b[] = new int*[2]{}	// Error! This means a static 1D array of pointers. You can't initialize
									// this with new!!!

	//	delete[] arr_b;	 Memory leak! Deletes array of pointers. However, what the arrays point to remains
	// in memory.
	std::for_each(arr_b, arr_b + 2, [](int* i) { delete i; });	// Fine!
	delete[] arr_b;	// Now, there's no leak!

	struct S {};
	S** arr_c = new S*[2]{ new S{}, new S{} };

	//delete[] arr_c;	// Again, just removing the top array!

	std::for_each(arr_c, arr_c + 2, [](S* ptr) { delete ptr; });
	delete[] arr_c;

}

void pay_special_attention_to_vectors() {
	struct S {};

	std::vector<S*> s{ new S{}, new S{} };
	// Memory leak! The array is destructed, and now we have unmanaged ptrs!
	for (auto ptr : s) {
		delete ptr;
	}

	// Now we're good!
}

struct S{};
void always_use_smart_ptrs() {
	using namespace std;
	vector<unique_ptr<S>> v{ };	// Default constructed S passed as unique ptr.
	v.push_back(make_unique<S>());
	v.push_back(unique_ptr<S>{new S{}});
	// Everything is fine now, without having to handle memory!

	// Note: Oddly enough, this initialization does not work!
	//vector<unique_ptr<S>> v{ unique_ptr<S>{new S{}}, unique_ptr<S>{new S{}} ;
}
