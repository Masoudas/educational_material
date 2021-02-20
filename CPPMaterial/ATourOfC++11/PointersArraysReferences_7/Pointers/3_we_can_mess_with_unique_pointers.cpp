/**
* Just like a normal pointer, we can mess with a regular pointer, and pass an element from the middle of a pack
* around into a new pointer. Be careful about it, and try and always work with an array as a whole.
*/
#include <memory>

void getting_a_pointer_to_the_middle_of_an_array_is_a_bad_idea() {
	std::unique_ptr<int[]> ptr = std::unique_ptr<int[]>{ new int[5] };

	std::unique_ptr<int> ptr_elem = std::unique_ptr<int>(&ptr[2]); // As the big guy says, disaster!
}