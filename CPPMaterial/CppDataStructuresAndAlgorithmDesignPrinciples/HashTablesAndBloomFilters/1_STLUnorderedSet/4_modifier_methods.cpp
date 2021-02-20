/**
* clear, insert, emplace, emplace_hint, erase, swap, extract, merge.
* 
* Note that emplace and insert returns a pair (allegedly). If the element already exists, no exceptions are raised, and the
* returned iterator points to the location of the existing element in the set. I can't find the pair it's supposed to return.
* It just returns a flag
* 
* Inserts a new element to the container, using hint as a suggestion where the element should go. The element is constructed 
* in-place, i.e. no copy or move operations are performed.
* 
* With erase, a bool is returned, indicating whether the element is removed from the list or not. Hence, if the element does
* not exist, no exceptions are thrown.
* 
* The extract method extracts a node from the set. The standard says Node handles can be used to transfer ownership of an 
* element between two associative containers with the same key, value, and allocator type 
* (ignoring comparison or hash/equality), without invoking any copy/move operations on the container element 
* (this kind of operation is known as "splicing"). Transfer between unique and non-unique containers is also permitted: 
* a node handle from a std::map can be inserted into an std::multimap, but not into std::unordered_map or std::set.
* To move the element in the new set, we need a special type, which can be deduced using move function, which is part of
* unordered_set. In conclusion, I think we should not work with nodes, because they may be dangerous, for causing collision,
* and they do, as the following example shows.
* 
* Ok, now we come to merge, which can be important. Essentially, merge combines two sets together, but this should not
* be taken lightly, because we should know if the merged set elements can be accessed, or that collisions don't occur.
* The standard says: 'Attempts to extract ("splice") each element in source and insert it into *this using the hash function 
* and key equality predicate of *this. If there is an element in *this with key equivalent to the key of an element from 
* source, then that element is not extracted from source. No elements are copied or moved, only the internal pointers of the 
* container nodes are repointed. All pointers and references to the transferred elements remain valid, but now refer into 
* *this, not into source.'
* As the example below shows, we once again see that merged sets may have repeated elements due to unequal hash values.
* Therefore, we should be cautious to use merge ONLY in case, we want to iterate over the merger of sets for example, and
* we really don't care about uniqueness. In other words, this is not a union of sets.
* 
*/
#include <iostream>
#include <unordered_set>

using u_set = std::unordered_multiset<int>;

void emplacing_repeated_element_in_set() {
	u_set s{ 1, 2, 3, 4 };

	auto itr = s.emplace(1);	// Of course!
	
	std::cout << *itr;
	s.clear();	// Clears the set, after which s.size() returns 0.
}

void erase_unordered_set() {
	u_set s{ 1, 2, 3, 4 };

	if (!s.erase(5)) {
		std::cout << "Removing non-existent element does not cause any exception\n";
	}
}

void extracting_node_from_set() {
	u_set s{ 1, 2, 3, 4, 5 };
	u_set s1{ 1 };

	auto node = s.extract(1);

	if (s.find(1) == s.end()) {
		std::cout << "The node of one has been removed";
	}
	s1.insert(move(node)); // Emplaces and invalidates the node.
	std::cout << "Size of set after emplacing the node is: " << s1.size() << ", which is bad, because now we have a repeated\
		element in the set";
}

void merge_u_sets() {
	u_set s{ 1, 2, 3, 4, 5 };
	u_set s1{ 5 };

	s.merge(s1);
	std::cout << "The merged set is has " << s.size() ;

}

//int main() {
//	merge_u_sets();
//}