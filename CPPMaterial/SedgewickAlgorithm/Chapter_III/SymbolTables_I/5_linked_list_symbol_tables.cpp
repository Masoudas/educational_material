/**
* The easiest implementation of symbol tables that come to mind is one that's based on a linked list. We
* set the elements as they come, and then sequentially search for them and delete from them. Note that as
* such, a symbol table would not be ordered.
* 
* How many comparisons do we require for placing N elements as such, starting from an empty search tree? 
* The answer would be N^2/2. Therefore, such an implementation is inefficient for large sets.
* 
* Note the implementation of the search method. If a key does not exist, we simply create a new one, as is 
* the convention in C++.
*/

#include <forward_list>
#include <algorithm>

template <typename Key, typename Value>
struct st_with_list {
	struct pair {
		Key key;
		Value val;
	};

	std::forward_list<pair> elems{};

	void put(Key key, Value value) {
		auto& loc = search(key);
		loc.val = std::move(value);
	}

	bool contains(const Key& key) {
		return std::find_if(elems.cbegin(), elems.cend(), [&](const auto& p) { return p.key == key; }) 
			!= elems.cend();
	}

	// Search for the key, and if it does not exist, create a new one.
	pair& search(const Key& k) {
		auto find = std::find_if(elems.cbegin(), elems.cend(), [&](const pair& p) {
			return p.key == k;
			});

		if (find == elems.cend()) {
			elems.emplace_front(k, Value{});
			return elems.front();
		}
		else {
			return *find;
		}
	}

	Value& operator[](const Key& key) {
		return search(key).val;
	}
};