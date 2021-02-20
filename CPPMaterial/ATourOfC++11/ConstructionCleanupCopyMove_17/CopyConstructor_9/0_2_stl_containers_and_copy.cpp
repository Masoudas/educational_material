/*
* So here's a question that is also asked in 17_3_1_mystery_of_memberwise_initialization.cpp.
* 
* Image I have a container (like vector, string, ...) in my class invariants. Then I make a copy out of the
* class using the copy constructor. Now, can a change in the copied version change the original version?
* 
* The short answer is no, because the default copy constructor does not literally copy the memory (which would've
* resulted in the aforesaid conclusion). However what it does is that it calls the copy constructor of each
* parameter. 
* 
* "C++ default copy/assign is memberwise; it recursively copies/assigns based on what the members do."
* 
* Some classes have value semantics, meaning (semantically) they're the same as built-in value types. stl
* containers are one such example. Hence, copying them, or assigning to them does not modify the original
* variable. This makes reasoning about the program rather easy.
* 
* Then we have reference semantics, where changes in one object affects all other aliases (essentially like
* a normal reference). 
* 
* We also have a pointer semantic too. This is almost the same as reference, with the difference that
* assignment to it rebinds who it points too. Examples are std::reference_wrapper, std::string_view, 
* std::shared_ptr<double>, gsl::span<char> and int*
* 
*/
#include <vector>
#include <iostream>
using namespace std;

class copying_container {
public:
	vector<int> vec;
	copying_container(initializer_list<int> list) {
		vec = list;
	}

	/* This is not the actual implementation of copy constructor.*/
	/*copying_container(copying_container& ref) {
		memcpy(this, &ref, sizeof(ref)); 
	}*/
};

void copying_a_class_with_container() {
	copying_container c1{ {1, 2, 3} };
	copying_container c2{ c1 };

	c1.vec[0] = 4;

	cout << c2.vec[0]; // This will print 1.
}

//int main() {
//	copying_a_class_with_container();
//}