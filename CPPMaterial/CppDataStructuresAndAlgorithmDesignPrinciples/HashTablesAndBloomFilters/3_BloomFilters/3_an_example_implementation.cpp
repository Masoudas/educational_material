/**
* An implementation reminder: So, I want to implement this example with a C-Style array to show a point. Note that
* if we decide to implement a C-Style array, the because the size of the array is not known at compile-time (and 
* we can't write bool filter[nBits] for that matter), then I have to create a pointer and create a dynamic array,
* which implies rewriting the destructor, which in turn implies rewriting copy and move ctor and assignment.
* 
* This naturally points out why we need to more or less use vector and array inside the class. However, if I really
* want to use C-style arrays, I can use smart pointers such as uique_ptr, which would invalidate the the array once
* it has been removed, not needing me to do anything special. Although I should state that I better use a shared_ptr
* here, because if we decide to copy the filter, then a unique_ptr is not copiable!
* 
* While we're here, vector<bool> is a specialization of vector for bool, that provides a compact storage of bits.
* 
*/
#include <memory>
#include <iostream>

class bloom_filter {
	int nBits;
	std::shared_ptr<bool> filter;
	// vector<bool> this would have been perfectly fine too.

	int hash1(int data) {
		return data % nBits;
	}

	int hash2(int data) {
		return (data / 7) % nBits;
	}

	int hash3(int data) {
		return (data / 11) % nBits;
	}

public:
	bloom_filter(int nBits) : nBits{ nBits } {
		filter = std::shared_ptr<bool>{ new bool[nBits] };	// Ok! No implicit constructor
		std::fill(filter.get(), filter.get() + nBits, false);	// Ok! We need to use get to access the actual
																// pointer value.
	}

	bool insert(int data) {
		filter.get()[hash1(data)] = true;
		filter.get()[hash2(data)] = true;
		filter.get()[hash3(data)] = true;

		return true;
	}

	bool lookup(int data) {
		auto contains = filter.get()[hash1(data)] && filter.get()[hash2(data)] && filter.get()[hash3(data)];
		if (contains)
		{
			std::cout << data << " may be present." << std::endl;
		}
		else
		{
			std::cout << data << " is not present." << std::endl;
		}

		return contains;

	}
};

//int main()
//{
//	bloom_filter bf(11);
//	bf.insert(100);
//	bf.insert(54);
//	bf.insert(82);
//	bf.lookup(5);
//	bf.lookup(50);
//	bf.lookup(2);
//	bf.lookup(100);
//	bf.lookup(8);
//	bf.lookup(65);
//}