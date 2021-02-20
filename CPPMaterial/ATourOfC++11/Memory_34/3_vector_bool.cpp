/**
* vector of bool is a specialization of vector for keeping bits in a compact manner. As opposed to bit set, this
* structure can hold a varying number of bits (like a vector).
* 
* Here's a look inside the class:
template<typename A>
class vector<bool,A> { // specialization of vector<T,A> (§31.4)
public:
	using const_reference = bool;
	using value_type = bool;
	// like vector<T,A>
	class reference { // suppor t zero-based subscripting in [0:v.size())
		friend class vector;
		reference() noexcept;
	public:
		~reference();
		operator bool() const noexcept;
		reference& operator=(const bool x) noexcept; // v[i] = x
		reference& operator=(const reference& x) noexcept; // v[i] = v[j]
		void flip() noexcept; // flip the bit: v[i]=˜v[i]
	};
	void flip() noexcept; // flip all bits of v
	// ...
}

* Moreover, as opposed to a bitset, the higher indexes hold higher bits (like a Big-Endian system I guess?).
* The big guy says "Use vector<bool> as you would any other vector<T>, but expect operations on a single bit to be
* less efficient than the equivalent operations on a vector<char>. Also, it is impossible in C++ to completely 
* faithfully mimic the behavior of a (built-in) reference with a proxy, so don’t try to be subtle about 
* rvalue/lvalue distinctions when using a vector<bool>".
* 
* Note: The overload for allowing v[i] = v[j] really did catch my eye! Why do we need it? Because a reference&
* is an lvalue reference, and we can't use it on the left hand side.
*/
#include <vector>

using std::vector;

void creating_vector_bool() {
	std::vector<bool> bits(10, false);
}