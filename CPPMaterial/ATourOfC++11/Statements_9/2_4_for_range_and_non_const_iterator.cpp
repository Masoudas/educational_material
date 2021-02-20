/**
* Note: Copy-on-write is a technique to reduce the memory usage of resource copies using deferred copy. The resource copies 
* are initially virtual (i.e. they share memory) and only become real (i.e. they have their own memory) on the first write 
* operation, hence the name ‘copy-on-write’. For example, the big guy once had an example of an image class that did not copy
* resources until we wanted to write in the image.
* 
* Now the standard points to something important. Note that for range calls the begin and end methods, and naturally these 
* two may change the object. When used with a (non-const) object that has copy-on-write semantics, the range-based for loop 
* may trigger a deep copy by (implicitly) calling the non-const begin() member function.
* 
* To avoid this scenario, there's a method inside the utility header that would create a const iterator which wraps our
* cbegin and cend methods of an iterator inside a begin and end method. 
* 
* Gosh golly of the methods inside iterator and utility headers. As we may recall, there's a method to create an iterator
* which wraps the push_back method of a vector, which allows insertion using an iterator! Totaly unrelated to this topic,
* but I just thought I should mention it.
*/

#include <utility>
#include <string>

using namespace std;

void for_range_may_cause_deep_copy_in_copy_on_write_objects() {
	struct cow_string { /* ... */ }; // a copy-on-write string
	cow_string str{};	

	// for(auto x : str) { /* ... */ } // may cause deep copy

//	for (auto x : std::as_const(str)) { /* ... */ }
}

void wrap_non_const_iterator_into_const() {
	string s{};

	auto& itr = as_const(s);	// Well, apparently because string has its own const iterator, nothing is done here!
}