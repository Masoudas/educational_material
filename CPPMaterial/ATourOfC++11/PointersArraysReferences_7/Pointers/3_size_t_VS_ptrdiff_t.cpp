/**
* size_t is defined as the result of sizeof operator. These can be simple typedefs. For example, in VS,
* this is unsigned int. It's defined not be larger than it has to be to keep memory size.
* 
* There are many functions in the stl that use size_t. For example, alloc, malloc, memcpy, etc.
* size_t is an unsigned, with size depending on the platform, whereas ptrdiff_t is a sigend version
* of size_t. Hence, if size_t is 32, then ptrdiff_t is also 32. In VS, this is just an int.
*/
#include <iostream>
#include <cstdint>

using namespace std;

void compare_size_t_and_ptrdiff_t() {
	static_assert(!is_unsigned_v<ptrdiff_t>, "Yo man!");

	size_t s = 10;
	size_t s1 = s * 10;	// Probably not, as size_t is probably at least unsigned int!

	cout << "size of size_t is " << sizeof(size_t) << " and size of ptrdiff_t is " << sizeof(ptrdiff_t);

}