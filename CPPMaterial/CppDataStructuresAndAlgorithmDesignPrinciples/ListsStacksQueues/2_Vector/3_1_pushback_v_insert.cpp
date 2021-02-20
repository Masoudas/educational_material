/**
* push_back method puts elements at the back of the vector, whereas insert puts them at any desired
* position. None of these two replace an existing item. They move around elements, just in different ways.
* For example, if we insert an element at position 0, it moves existing elements to position 1 to end.
* 
* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
* push_back:
*	If size < capacity: then set the element at the last position, and increase size.
*	else: allocate twice the size, copy or move elements, make original data point to new memory, 
* insert the new element. (Note: even resizing is compiler dependent. I can't see this in MSVC)
* 
* Hence, push_back has O(1) or O(n) complexity.
* 
* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
* insert:
*	An iterator to where the element should be placed need to be provided. The operation takes care of
*  memory reallocation if required. Hence, it takes O(n) time.
* 
* Note that there's no push_front function. Pushing in the front is done using insert. Note also that insert
* does NOT mean replacing the elements!!! It means inserting new ones! Hence, if you put one in the beginning,
* the new element is inserted, and the rest are pushed to right. Akh! I make this mistake so many times!
* 
* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
* 
* Note that both push_back and insert have a const ref and an rvalue method. The const ref method is used for 
* copying the element, whereas the rvalue element is used for move (which can also be copied, if it does not have a 
* move constructor). Why not take an element, rather than a reference, so that the copy takes place directly?
* Perhaps because we needed to say data[n] = std::move(value), and this is unnecessary overhead.
* 
* Logical conclusion of this discussion is to always use const X& for copy operations of my own class, 
* like a class copy constructor does.
* 
* Note that insert uses copy/move assignment rather than constructor, because the memory already exists
* when assigning the new variable.
* 
* One thing that's very interesting is that when expanding the array with insert, the elements are constructed,
* and not assigned! The expectation is that we write:

T* t = new T[] // memory allocation.
std::copy(...) // Assignemnt

* However, what happens is that the class uses the emplace methods. To understand how emplace works, see 7. 
* What it does basically is that the construction of allocated memory is done using the constructor directly,  
* which is cool! Even though push_back and insert use emplace methods now, perhaps this was not the case
* in older versions. Therefore, I should always prefer emplace methods.
*/

#include <vector>
#include <iostream>

using namespace std;

struct X {
	int x;
	X(int x) : x{x}{}
	X(X&& other) noexcept : x{ other.x } { cout << "Using move constructor\n"; }
	X(const X& other) : x{ other.x } { cout << "Using copy constructor\n"; }

	X& operator=(const X& other) { x = other.x; cout << "Inside copy assignment\n"; return *this; }
	X& operator=(X&& other) noexcept { x = other.x; cout << "Inside move assignment\n"; return *this; }
};

template <typename T>
void print_size_and_capacity(const vector<T>& vec) {
	cout << "Size is: " << vec.size() << " and capacity is: " << vec.capacity() << '\n';
}

void push_back() {
	X x1{ 1 };
	X x2{ 2 };
	X x3{ 3 };

	vector<X> vec{};	// Capacity is zero;

	vec.push_back(x1);	// Set first element, capacity is 1, so is the size.
	print_size_and_capacity(vec);

	vec.push_back(std::move(x2));	// Set second element, capacity is 2, so is the size.
	print_size_and_capacity(vec);

	for (int i = 0; i < 6; i++) {
		vec.push_back(std::move(x2));
		print_size_and_capacity(vec);
	}
	
}

void insert() {
	X x1{ 1 };
	X x2{ 2 };
	X x3{ 3 };

	vector<X> vec{x1, x2, x3};	// Capacity is three. Uses copy constructor 6 times, three times to form initializer
							// list, and three times for assignment.

	cout << "Inserting a new element \n";
	vec.insert(vec.begin(), x1);	// assign to first element {x1, x1, x2, x3}
									// Results in one copy and three moves.

	cout << "Inserting a new element with std::move\n";
	vec.insert(vec.begin(), std::move(x1));	// This time, we use five moves {x1, x1, x1, x2, x3}
}

//int main() {
	//push_back();
	//insert();
//}