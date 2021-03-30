/**
* In this example, we implement an ordered symbol table using a vector. Insertion of elements is done using
* the rank of the element. Note that when inserting an element, we need to move the elements to the left,
* which is taken care of for us by the interal operations of vector.
* 
* To mimic the implementation of binary search, as we may recall, the standard provides the std::lower_bound,
* which returns an iterator to the first element greater than or equal to the given value (or end). To make
* our implementation a bit easier, we actually return an iterator to the location rather than the index.
* Note, however, that for the contains method, we actually use the binary_search method to tell whether or
* not the element exist.
* 
*/
#include <vector>
#include <algorithm>

template <typename Key, typename Value>
class sorted_vector_ordered_st {
	struct Node {
		Key k;
		Value v;
	};

	std::vector<Node> elems{};

	// end iterator if elem not found, else either exact location of element, or first element greater than
	// current.
	auto rank(const Key& k) {
		return std::lower_bound(
			elems.begin(), elems.end(), k, [&](const auto& p) { return p.key < k; });		
	}

	void insert(Key key, Value value) {
		auto loc = rank(key);

		if (loc == elems.end()) {
			elems.emplace_back(std::move(key), std::move(value));
		}
		else if (loc->first == key) {
			loc->val = value;
		}
		else {
			elems.insert(loc, { std::move(key), std::move(value) });
		}
	}

	Value& min() {
		return elems[0];
	}

	Value& max() {
		return elems[elems.size() - 1];
	}

	bool contains(const Key& k) {
		return std::binary_search(
			elems.cbegin(), elems.cend(), k, [&](const auto& p) { return k == p.key; });
	}

	auto begin() {
		return elems.begin();
	}

	auto end() {
		elems.end();
	}

	void erase(Key& k) {
		auto loc = rank(k);

		if (loc != elems.end()) {
			elems.erase(loc);
		}
	}
	
	// We can't implement the floor method here. Suppose the symbol table is empty, we can't return a
	// valid key. Moreover, Suppose that the given Key argument is less than our first element. Again,
	// we can't return a key. This is unless we decide to return a unique_ptr, which may have null in it!
	// A rather better option is to use lower_bound and upper_bound for such cases.
	// Key floor(const Key& key);

	// We can't return a key for ceil with the same reasoning. 
	// Key ceil(const Key& key);

	// Keys greater than equal to lo to keys less than equal hi.
	size_t size(const Key& lo, const Key& hi) {
		auto loc_lo = rank(lo);
		auto loc_hi = rank(hi);

		if (loc_lo == elems.cend()) return 0;
		return *loc_hi.key == hi ? std::distance(loc_lo, loc_hi) + 2 : std::distance(loc_lo, loc_hi) + 1;	
	}

	bool isEmpty() {
		return elems.empty();
	}
};