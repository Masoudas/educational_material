/**
* As an interesting side node, there's a for_each method in std that works with pointers and
* lambda, applying the lambda to the method.
* 
* for_each is exactly like the normal for(auto x: container), point being, x is not a pointer, but rather
* the actual value of each element.
*/
#include <algorithm>
#include <iostream>

void std_foreach() {
	int arr[] = { 1, 2, 3 };

	std::for_each(arr, arr + sizeof(arr) / sizeof(arr[0]), [](int x) {std::cout << x << "\n"; });
}