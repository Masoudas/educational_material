/**
* A copy constuctor or assignment is considered a proper one if the following two conditions are met:
* 
* 1-	Equivalence: x==y and f(x) == f(y) for each f that depends only on the values of x and y 
* (as opposed to having its behavior depend on the addresses of x and y)
* 
* 2-	Independence:  After x=y, operations on x should not implicitly change the state of y, that is
* f(x) does not change the value of y as long as f(x) doesn’t refer to y.
* 
* Example: The default copy behavior of vector and int is as such. 
* (Me: For example, with vector, the T* is implicitly held. So we way assume that a copy constructor copies
* the memory associated with it. Hence, the two objects will be independent. For example, this is the case with
* list as well. Perhaps, we should assume that for all stl containers, a memcpy is performed for the list of 
* underlying data).
* 
* Sometimes, non-value parts of an object are not copied. For example, the allocater is not copied when an 
* stl container is copied. This does not violate the equivalence condition though, hence it's allowed.
* 
* Indepence however is often violated, especially if pointers are involved. Hence, shallow copies should be avoided.
* Objects that are not independent after copy are entangled objects.
*/
#include <string>
#include <list>
#include <iostream>

using namespace std;

void copying_list_does_not_affect_original() {
	string s1 = "Ahoy";
	
	list<string> l1{};
	l1.push_back(s1);

	list<string> l2{ l1 };

	*l1.begin() = "Ahoy Captain";

	cout << "changing original list does not change the second list. This prints Ahoy: " << *l2.begin();
}

//int main() {
//	copying_list_does_not_affect_original();
//}