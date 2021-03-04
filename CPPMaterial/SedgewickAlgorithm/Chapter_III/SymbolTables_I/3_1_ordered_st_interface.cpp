/**
* If our keys are comparable to one another, we can expand the symbol-table interface to include ops that 
* involve the relative order of keys. More important, in such implementations, we can think of the symbol 
* table as keeping the keys in order and consider a significantly expanded API that defines numerous natural 
* and useful operations involving relative key order.
* 
* Question: Are we talking here about a stable symbol table, or order referes to the relative order of 
* elements? For example, if we consider the std::map (and not unordered_map) in C++, we see that such a map
* is ordered using the comparison method. Therefore, there's no talk of stability. In fact, all the methods
* we talk about in this interface have something to do with relative order of elements (min and max for example)
* and not with stability (the order through which elements were put in.) Above all, note that iterators for
* std::map traverse the keys in relative order (that is min to max or max to min depending on the type of
* comparison method supplied.)
* 
* Note that as such, we can define several cool operations on maps, such as size(key lo, key hi) that would
* return the number of elements between a range, or lower_bound and higher_bound in map that would return an
* iterator to the first element below or above a certain value.
* 
* Notice how this symbol table demands a comparison operator for keys, which yours truely set to std::less 
* from the functional interface.
*/

#include <functional>

template<typename Key, typename Value, typename Comp = std::less<Key>>
class ordered_st_java {
public:
	virtual	void put(Key, Value) = 0;			// put key - value pair into the table
												// (remove key from table if value is null)
	virtual Value get(const Key&) = 0;			// value paired with key
												// (null if key is absent in Java)
	virtual void remove(const Key&) = 0;		// remove key (and its value) from table
	virtual bool contains(const Key&) = 0;		// is there a value paired with key ?
	virtual bool isEmpty() = 0;					// is the table empty ?
	virtual int size() = 0;						// number of key - value pairs
	virtual Key min() = 0;						// smallest key
	virtual Key max() = 0;						// largest key
	virtual Key floor(const Key&) = 0;			// largest key less than or equal to key
	virtual Key ceiling(const Key&) = 0;		// smallest key greater than or equal to key
	virtual int rank(const Key&) = 0;			// number of keys less than key
	virtual Key& select(int k) = 0;				// key of rank k
	virtual void deleteMin() = 0;				// delete smallest key
	virtual void deleteMax() = 0;				// delete largest key
	virtual int size(const Key&, const Key&) = 0; // number of keys in[lo..hi]
	
	// virtual forward_iterator keys(const Key& lo, const Key& hi) = 0; // keys in[lo..hi], in sorted order
	// virtual forward_iterator keys() = 0;		// all keys in the table, in sorted order

	virtual ~ordered_st_java() = 0;
};