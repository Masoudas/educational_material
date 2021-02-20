/**
* We're particularly interested in the question: What happens if I read or write to an outside range element?
* The answer is of course undefined behavior, because the under the hood memory allocation is pointer based,
* and does not allow such assignemnts. Compare these to push_back, or insert, which can hanfle this scenario.
*/
#include <vector>

using std::vector;

void inserting_out_of_index() {
	vector<int> v{ 1, 2, 3, 4 };

	int v1 = v[5]; // Undefined, may throw an exception (does throw an exception in MSVC).
	v[5] = 2; // Undefined, may throw an exception (does throw an exception in MSVC).
}

//int main() {
//	inserting_out_of_index();
//}