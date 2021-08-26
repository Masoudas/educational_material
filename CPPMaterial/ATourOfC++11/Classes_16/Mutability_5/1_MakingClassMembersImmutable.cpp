/**
 * Question is, can we define class members const? Yes we can. However, we can't modify them using constructors, 
 * or any other function for that matter. This is because memory space is declared with class memory instantiation.
 * Hence, it can't be modified with constructors.
 *
 * Me: Note that we CAN'T change the value of const member classes, unless we use const_cast. Later on, we shall
 * learn that we can change class memebers inside const methods, but that's a totally separate thing. So, don't
 * confuse the two. Only a const_cast allows one to change const entities, class member or not.
 * 
 * Where can we initialize const class members? Not inside the constructor, becaus by then the memory of the class is allocated.
 * However, we can assign to it with the : operator in the constructor.
 */

struct initialize_const_class {
	const int i;	// To be initialized with the : operator.
	const int j = 10;	// Fine.
	initialize_const_class() : i{ 5 } {
	}
};

int main() {
	initialize_const_class c_class{};
}