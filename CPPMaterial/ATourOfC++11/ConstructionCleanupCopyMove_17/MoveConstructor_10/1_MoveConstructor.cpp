/**
* 
* The notion of move constructor is to allow for moving objects, rather than creating a copy of the object.
* For example, we don't make a copy of a car when we lend ours to someone, we move ownership.
* 
* Same goes for a move assignment. The idea is that the object is about to be destroyed. For both move assignment
* and constructor, we take a non-const (rvalue) reference. non-const to allow for modification of the argument.
* 
* Imagine that we have a pointer in our class. The idea is that we just swap that pointer in assignment for example,
* leaving the original pointer with our current pointer. This way, our old data is destroyed upon destruction
* of the moved object (which is good, because we know that rvalue passed objects are destroyed). (Me: This mostly
* applies to move assignment. With move construction, we generally set to null).
* 
* In particular, move operations typically do not throw exceptions; they don’t
* acquire resources or do complicated operations, so they don’t need to.
* 
* As we may recall with the discussion on rvalue and lvalue references, we have to tell the compiler that we want
* to move, using std::move. The compiler does not move anything for us on its own.
* 
* In the absense of move assignment and constructor, the copy version is used.
* 
* As a reminder, note that for built-in types, a move operation simply makes a copy of the value.
* 
*/
#include <memory>

template <typename T>
struct matrix {
	T* p;

	matrix& operator=(matrix &&ref) noexcept {
		std::swap(p, ref.p);	// Just changing pointer. Not setting the other to null.
		return *this;
	}
};

void using_swaped_matrix() {
	matrix<int> *m1 = new matrix<int>{};
	matrix<int> m2{};

	*m1 = std::move(m2);	// resources are swaped, which is fine, because m2 is about to be destroyed.
}