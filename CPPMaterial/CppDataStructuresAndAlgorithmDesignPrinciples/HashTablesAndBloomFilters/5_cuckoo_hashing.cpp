/**
* The idea of cuckoo hashing is fairly simple. We create two tables, and to each we associate a different hashing
* function. When inserting an element, if the slot in one hash table is full, we use the second table. 
* 
* The suggested strategy for implementing this hash table is as follows:
* - If the location in table 1 is full, place the new element there, and move the old element to table two.
* - Compute the hash of the element, and place it there. If the slot is full again, move back to table one.
* 
* An important difference between this hashing method and the previous ones therefore is that we may move an
* element from its place once inserted in the table.
* 
* There are a couple of issues regarding this strategy:
* 1- We may have a cyclic infinite loop, that happens because hashes collide with each other. The solution (not
* really a solution, but ...) is to break the loop if we can't insert the element after a number of iterations,
* and rehash the table. However, with smart strategies and wisely chosen hash functions, we can achieve a
* performance of amortized O(1) with high probability.
* 2- What's more a source of problem in my opinion is that we may move one element to another table. But that 
* element will have the same hash value as the element we just put in. So, when the user searches for element,
* the hash value would be the same, and we get the wrong element! Therefore, a check for equality is important.
* 
* Question is, how do we search for an element inside the hash table? The idea is that we compute the hash of
* element, and then, we have to check and see if the element we've found is equal to the given element. If this
* were'nt the case, we have to search the second table. Note that this strategy never returns the wrong element,
* because every time we insert an element in the hash table, it goes to the place corresponding to its hash.
* Hence the term cuckoo perfect hashing (almost :D).
* 
* In conclusion, the insertion cost of this strategy is O(n), but the find cost is O(1).
* 
* In what follows, we implement a cuckoo hash for unsigned ints.
*/
#include <vector>

using std::vector;
/**
* A unidirectional iterator for the map.
*/
class cuckoo_hash_map_iterator {
	using uint = unsigned int;
	using t_itr = std::vector<uint>::iterator;

	t_itr begin_1, end_1, begin_2, end_2, c_elem;

private:
	// One must wonder, whether one should implement a decrement too!
	void increment() {
		// Note that if b1 = e1, c_elem is set to b2 in the constructor.
		if (c_elem == end_2) {
			return;
		}

		++c_elem;
		if (c_elem == end_1) {
			c_elem = begin_2;
			increment();
		}
		else if (*c_elem == -1) {
			increment();
		}
	}

public:
	cuckoo_hash_map_iterator(t_itr b1, t_itr e1, t_itr b2, t_itr e2) : begin_1{ b1 }, begin_2{ b2 }, 
		end_1{ e1 }, end_2{ e2 } {
		c_elem = begin_1;

		if (c_elem == e1) {
			c_elem = e2;
		}

		if ( c_elem != e2 && *c_elem == -1 ) {
			increment();
		}
		
	}

	cuckoo_hash_map_iterator& operator++() {
		increment(); 
		return *this;
	}

	cuckoo_hash_map_iterator operator++(int) {
		auto temp = *this;
		++(*this);
		return temp;
	}

	uint& operator*() {
		return *c_elem;
	}

	bool operator!=(const cuckoo_hash_map_iterator& rhs) {
		return this->c_elem == rhs.c_elem;
	}

	t_itr operator->() {
		return c_elem;
	}
};

class cuckoo_hash_map {
	using uint = unsigned int;
	using iterator = cuckoo_hash_map_iterator;	// Pretty clear by now that this aliasing occurs here!
	
	uint N = 7;
	uint max_insertion_itr = N * 2;

	vector<uint> table_1 = vector<uint>(7, -1);	// We know that this value is not -1 in fact, but for having
												// a comparison reference point!

	vector<uint> table_2 = vector<uint>(7, -1);

	int hash1(uint v) {
		return v % N;
	}

	int hash2(uint v) {
		return (v / N) % N; // Don't forget that this is an integer division.
	}

public:
	std::vector<uint>::iterator find(uint val) {
		auto h_1 = hash1(val);
		if (table_1[h_1] == val) {
			return table_1.begin() + h_1;
		}

		auto h_2 = hash2(val);
		if (table_1[h_2] == val) {
			return table_2.begin() + h_2;
		}

		return {};	// Return an empty iterator
	}

	bool erase(uint key) {
		auto loc = find(key);

		// Don't create an object every time!
		if (loc == std::vector<uint>::iterator{}) {
			return false;
		}

		*loc = -1;
	}
	
	// There's a problem with returning false here. Because this would indicate that the inserted value
	// was not placed, whereas it will be the first value we insert! We can repair this perhaps by returning
	// a pair, indicating the value that was not placed, or we could use rehashing.
	bool insert(uint val) {
		uint iteration = 1;

		return insert_impl(val, iteration, true);
	}

private:
	bool insert_impl(uint val, uint iteration, bool in_table_1) {
		if (iteration > max_insertion_itr) {
			return false;
		}

		if (in_table_1) {
			int hash = hash1(val);
			if (table_1[hash] != -1) {
				int occup_elem = table_1[hash];
				table_1[hash] = val;
				return insert_impl(occup_elem, ++iteration, false);
			} 
			
			table_1[hash] = val;
			return true;
		}
		else {
			int hash = hash2(val);
			if (table_2[hash] != -1) {
				int occup_elem = table_2[hash];
				table_2[hash] = val;
				return insert_impl(occup_elem, ++iteration, false);
			}

			table_2[hash] = val;
			return true;
		}
	}

	iterator begin() {
		return iterator{ table_1.begin(), table_1.end(), table_2.begin(), table_2.end() };
	}

	iterator end() {
		return iterator{ table_1.end(), table_1.end(), table_2.end(), table_2.end() };
	}
};