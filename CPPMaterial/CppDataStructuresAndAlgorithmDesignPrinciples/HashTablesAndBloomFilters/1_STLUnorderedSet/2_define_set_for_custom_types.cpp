/**
* Question: How de we create a set for a custom type?
* 
* Answer: We need to create a hashing function for the given type. Another thing that we need is the equal_to 
* functional, which should be overloaded as well.
* 
* Now, a question arises here: Do we want two distinct objects have the same hash or not? That is, even if they are equal?
* The answer to this lies in the application. However, here's the fun part. If we decide that we want to use distinct object,
* we don't have to specialize neither the equal_to function, nor the hash function. Instead what we do is to use pointers
* to create the set, in which case pointers can be hashed, as well as equality of pointers is well defined.
* 
* Question: How should we overload the equal_to functional interface? Of course we know that equality of two 
* classes is not related to their hashes. But still why aren't we saying that two classes are equal if their
* hashes are equal? This is discussed in 1. We need to ensure that elements of the same hash are unique, so that the set
* property is held. Hence, the need for equal to functional.
* 
* Question is, should we add the hash functional specializion in the std or in the namespace of the type? Note once again that specialization cannot occur in third
* party namespace. So add the hash inside stl. 
* 
* Note that as opposed to maps, there needs to be no default constructor for the type (I guess).
*/
#include <unordered_set>
#include <algorithm>
#include <iostream>

namespace ns{
	struct my_type {
		int t;
	};

}

template<>
struct std::hash<ns::my_type> {
	size_t operator()(const ns::my_type& v) const {
		return 0;
	}
};

template<>
struct std::equal_to<ns::my_type> {
	bool operator()(const ns::my_type& _Left, const ns::my_type& _Right) const {
		return _Left.t == _Right.t;	// Has nothing to do with the hash value of course!
	}
};

void set_of_custom_type_with_no_equal_objects() {
	using namespace ns;
	std::unordered_set<ns::my_type> s{};

	s.insert(my_type{});

}

void set_of_custom_type_with_distinct_objects_but_possible_equal_content() {
	using namespace ns;

	std::unordered_set<ns::my_type*> s{};

	s.insert( new ns::my_type{} );
	s.insert( new ns::my_type{} );
	s.insert( new ns::my_type{} );

	std::cout << "Set size would be three: " << s.size();


}


//int main() {
//	set_of_custom_type_with_distinct_objects_but_possible_equal_content();
//}
