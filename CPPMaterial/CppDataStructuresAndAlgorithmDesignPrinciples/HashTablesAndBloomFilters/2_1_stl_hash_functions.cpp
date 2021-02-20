/**
* C++ STL has provided hashing fascilities for various different basic types. These are actually specializations
* of a templated struct called hash in the algorithm header. The result of hashing is size_t, which makes sense
* because the hash result is a positive integer! 
* 
* Question: How do we hash a custom type? Well, normally we want to add a hash function inside the type, but if
* we wanted to get cute, we could actually create a new namespace, or add our hash value to stl itself, and then
* define another specialization to hash. But apparently, we can't specialize a templated type in a newly created
* namespace (go figure!). Don't forget the const post-modifier!
*/
#include <algorithm>
#include <string>
#include <iostream>

class S {
	friend std::hash<S>;
	int w;
};

// Isn't this in the global name space? Nope. It's in std. It's like writing the definition of a class outside
// header function.
template<>
struct std::hash<S> {
	size_t operator()(const S& val) const {
		return 1;
	}
};

//namespace new_std {
//	using namespace std;	// Yeah! Don't forget that this is dragging the name space, not using statement!
//
//	template<>
//	struct hash<S> {
//		size_t operator()(const S& val) {
//			return 1;
//		}
//	};
//}


void hashing_basic_types() {
	std::hash<std::string> str_hasher{};
	size_t str_hash_val = str_hasher("A B C D E F G, How I wonder what you are.");
	
	std::hash<double> dbl_hasher{};
	size_t dbl_hash_val = dbl_hasher(5.32);

	S s{};
	std::hash<S> s_hasher{};
	std::cout << s_hasher(s);
}


//int main() {
//	hashing_basic_types();
//}