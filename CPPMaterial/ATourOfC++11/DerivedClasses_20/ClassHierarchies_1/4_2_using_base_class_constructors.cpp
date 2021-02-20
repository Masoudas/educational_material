/**
* Just like we can drag a base class method with the scope operator, we can drag its constructors using the scope
* operator, together with the name of the class (because after all, a constructor is a method adjacent with the same
* name as the class.). We sometimes need to drag the base class constructors because as we already know, constructors
* are not inherited
* 
* An interesting example is given below, where we extend the vector class to include a range check. Now, if we 
* leave the class without constructors, we wouldn't be able to create a vector with for example the init_list
* constructor. This is the reason why we need to drag the constructors in as well.
*/

#include <vector>

using namespace std;

class vec_with_range_check : public vector<int> {
public:	
	// We can't use override, because the base method is not virtual!
	_NODISCARD const int& operator[](const size_type index) const noexcept {
		if (index < 0 || index >= size()) {
			throw "Out of range";
		}
		return vector<int>::operator[](index);	// Don't forget that writing operator[] here is wrong and causes
												// an infinite recursion.
	}

	_NODISCARD int& operator[](size_type i) { 
		if (i < 0 || i >= size()) {
			throw "Out of range";
		}

		return vector<int>::operator[](i);
	}
};