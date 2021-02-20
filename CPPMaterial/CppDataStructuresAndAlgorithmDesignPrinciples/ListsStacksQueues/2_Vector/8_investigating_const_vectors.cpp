/**
* Just like an array, a const vector has constant internal data, and cannot be modified. 
* 
* What happens if we try and emplace or emplace_back with const vector? Because none of the methods have a
* const qualifier, then we can't access them with the const method. This is to be expected, as a lack of const
* qualifier for any class method implies we can't access it thorugh consts (Note that this in turn implies that
* when I write a class as such, I don't need to delete a method with const qualifier. That would be redundant
* to say the least).
* 
* 
*/

#include <vector>

using std::vector;

void constant_vector_usage() {
	const vector<int> v{ 1, 2, 3, 4 };
}