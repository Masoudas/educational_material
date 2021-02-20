/**
* Note that Binary Search Trees achieve a search complexity of O(log(n)), which is very fast, but not fast enough 
* for situtations where tons of queries are required.
* 
* In those cases, we prefer to use hash functions. Hash functions map our data to (possibly colliding) integers, 
* making them ideal for indexing, which can be of order 1. 
* 
* Hashing functions can be as simple as module n remainders, quotient of division by a number, or more complicated 
* ones such as SHA256.
* 
* As an example, we implement a simple hash_table for unsigned integers, disregarding the possiblity of collision.
*/
#include <vector>

class hash_map {
	using uint = unsigned int;
	std::vector<uint> table;
	size_t m;

	hash_map(size_t n) : table(n, -1), m{ n } {};

	void insert(uint v) {
		table[v % m] = v;
	}

	void remove(uint v) {
		table[v % m] = -1;
	}

	bool find(uint v) {
		return table[v % m] == -1;
	}
};