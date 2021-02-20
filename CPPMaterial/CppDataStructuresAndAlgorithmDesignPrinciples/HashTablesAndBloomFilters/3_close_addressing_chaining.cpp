/**
* As we know, a simple hashing of elements is not enough, and we may in fact have collisions. There are a couple of algos
* out there for avoiding collision, which are:
* 1- Chaining
* 2- Linear probing
* 3- Quadratic probing
* 4- Cuckoo hashing.
* 
* We shall investigate each method in the following sections.
* 
* In chainging method, if two elements have the same hash value, we simply chain them together, as part of the same hash
* index. The chain data structure can be a linked list, or a vector. It's been suggested to use linked list, to speed up
* the deletion process. Each of these nodes is called a bucket.
* 
* The point here is that the elements inside a bucket have the same hash value. Now, for example if we wanted to implement
* a set (which we know only holds unique elements), we can use an equality operator to check whether the given element
* equals the ones already in the bucket. If this is not a set however, we can just simply add the element to the bucket,
* as we do below.
* 
* In any case, the cost of insertion is (almost) O(1). deletion is proportional to the time it takes to delete the data
* from the chain, which is (almost) O(n) for both a list and a vector.
* 
* Now, if the hash table is very small compared to the range of elements, we'll have a lot of collision. On the other hand,
* a very big table might be sparse. To measure this fact, we have a load factor defined as:
* load_factor = number_of_keys/hash_table_size.
* 
* For example, for a hash of module 7, hash table has size 7. Now, a key number of 6 generally indicates one key per table
* position, which means O(1) for all operations. We want load factor to be generally close to 1, because LF < 1 means sparse
* data set, and LF > 1 means O(n) for operations. 
* 
* We may think of the case where all keys fall in the same hash value, in which case even though the LF is one, all operations
* will take O(n). Whereas this may be valid for some cases, note that this usually shows that the hash function has a problem,
* for it gives us always the same value.
* 
* As we'll see with the unordered_set of STL, LF is used for when rehashing takes place. rehashing as know, is the process
* of recreating the hash table, using a new hash function. In STL for example, the threshold is set as one, but we can change
* the value. 
* 
* In the following example, we implement such a hash strategy, with the hashing function as modulo of the value.
* 
* Question: Something very interesting about the iterator of unordered_set in C++ is that the iterator of a bucket and the 
* entire set is that of an iterator of a set. How is this possible? No idea! The question that may arise here is that how do
* I proceed to write a not too complicated iterator for this hash_map? There are two issues, one is that we have to pass over
* the empty locations in the vector. Moreover, we have to traverse the entire forward list. If I were the implementors of 
* stl, I probably would have passes a refernce to the node of the next bucket in each bucket.
*/
#include <vector>
#include <forward_list>
#include <iostream>


class iterator_hash_map {
	using table = std::vector<std::forward_list<int>>;
	using table_itr = std::vector<std::forward_list<int>>::iterator;
	using bucket_itr = std::forward_list<int>::iterator;

	table_itr table_itr_b;
	table_itr table_itr_e;
	bucket_itr node_b;
	bucket_itr node_e;

public:
	iterator_hash_map(table_itr begin, table_itr end) : table_itr_b{ begin }, table_itr_e{ end } {
		if (begin != end) {
			node_b = table_itr_b->begin(); node_e = table_itr_b->end();
			if (node_b == node_e) find_next();
		}
		else {
			// Is this very odd?
			node_b = std::forward_list<int>::iterator{};
			node_e = std::forward_list<int>::iterator{};
		}

	}

	void find_next() {
		if (node_b != node_e) { // If this bucket still can move forward, find next.
			++node_b;
		}

		if (node_b == node_e) {	// Check again and if this bucket has reached its end.
			if (++table_itr_b != table_itr_e) {
				node_b = table_itr_b->begin();
				node_e = table_itr_b->end();
				if (node_b == node_e) find_next();
			}
		}
	}

	iterator_hash_map& operator++() {
		find_next();
		return *this;

	}

	iterator_hash_map operator++(int) {
		auto temp = *this;
		++* this;
		return temp;
	}

	bool operator==(const iterator_hash_map& rhs) {
		return (this->table_itr_b == rhs.table_itr_b) && (
			this->table_itr_b == this->table_itr_e || this->node_b == rhs.node_b);
	}

	bool operator==(iterator_hash_map&& rhs) {
		return *this == rhs;
	}

	bool operator!=(const iterator_hash_map& rhs) {
		return !(*this == rhs);
	}

	bool operator!=(iterator_hash_map&& rhs) {
		return !(*this == rhs);
	}

	int& operator*() {
		return *node_b;
	}

	iterator_hash_map& operator=(const iterator_hash_map& rhs) {
		this->node_b = rhs.node_b;
		this->node_e = rhs.node_e;
		this->table_itr_b = rhs.table_itr_b;
		this->table_itr_e = rhs.table_itr_e;
		return *this;
	}

};

class hash_map {
	int N;

	int hash_module;
	std::vector<std::forward_list<int>> table;

public:
	using iterator = typename iterator_hash_map;

	hash_map(int n) : hash_module{ n } {
		table = std::vector<std::forward_list<int>>( n, std::forward_list<int>{} );
	} 

private:
	size_t hash(int val) {
		return ((val % hash_module) + hash_module) % hash_module;	// To get a positive value.
	}

public:
	bool contains(int val) {
		auto hval = hash(val);
		auto find = std::find(table[hval].begin(), table[hval].end(), val);

		if (find == table[hval].end()) {
			return false;
		}

		return true;
	}

	bool insert(int val) {
		auto hval = hash(val);
		auto find = std::find(table[hval].begin(), table[hval].end(), val);

		if (find == table[hval].end()) {
			table[hval].push_front(val);
			N++;
			return true;
		}

		return false;
	}

	void remove(int val) {
		auto hval = hash(val);

		if (!table[hval].remove(val)) {
			N--;
		}
	}

	double load_factor() {
		return double( N ) / hash_module;
	}

	void rehash() {
		if ((load_factor() - 1 > 0.1) && (1 - load_factor() < 0.1)) return;
		auto old_table = std::move(table);

		++hash_module;
		table = std::vector<std::forward_list<int>>(hash_module, std::forward_list<int>{});
		for (auto& list : old_table) {
			for (int val : list) {
				insert(val);
			}
		}
	}
	
	iterator begin() {
		return iterator{ table.begin(), table.end() };
	}

	iterator end() {
		return iterator{ table.end(), table.end() };
	}
};


void testing_iterator() {
	hash_map m{5};

	if (m.begin() == m.end()) {
		std::cout << "The set is empty\n";
	}

	m.insert(0);
	m.insert(5);

	m.insert(4);
	m.insert(9);


	std::cout << "The content of the set is:\n";
	for (auto& val : m) { // For this to work, we need to rvalue overloads!
		std::cout << val << '\t';

	}
	
	std::cout << '\n';

}

void test_close_address_method() {
	hash_map m{ 7 };

	m.insert(1);
	m.insert(2);
	m.insert(8);

	if (m.contains(1)) {
		std::cout << "Contains 1\n";
	}

	m.remove(1);

	if (m.contains(8)) {
		std::cout << "Contains 8\n";
	}
}


//int main() {
//	//test_close_address_method();
//	testing_iterator();
//}

