/**
* We must not forget that built-in types don't have destructors!! Hence, if we're using a template
* for example, we can't simply call the destructor of the template.
*/
#include <utility>

void moving_array_elements_forward() {
	int arr[] = { 1, 2, 3, 4 };

	for (int i = 2; i > 0; i--) {
		std::swap(arr[i], arr[i + 1]);
	}

	// ~arr[0]();	// We can't say now destruct the first element.
	// ~arr[0]; // This is the bitwise not you morron!
}