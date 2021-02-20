/**
* In this activity, we will create a validator to check if an email address requested by a user is already taken.
* 
* The strategy we use to get multiple hash values is to use the bytes of standard hash. So, each byte will be 
* considered the result of one hash function. So, each byte has a value between 0 and 255, and what we do is to
* set the bit corresponding to this value in the filter equal to one. In this scheme, the number of hash functions
* can be at most 4, but with a longer hash (such as MD5 which the book uses and has 128 bits), we could have as
* many as 128/8 hashes!
* 
* Finally, note that the book asks for the size of the filter (which I set to 256 directly here), but the book says
* it can be less than 256 as well. The problem is that if the size is less than 255 and the hash value byte is
* greater than that, then we get into trouble! So, I didn't take the size.
* 
* 
*/
#include <string>
#include <vector>
#include <iostream>

class BloomFilter {
	using email_addr = std::string;
	using md5_hash = std::hash<const char*>;
	using filter_type = std::vector<bool>;

	md5_hash hasher{};

	static constexpr int filter_size = 256;
	filter_type filter;

	static constexpr int hashSize = 32 / 8;
	unsigned char hashValue[hashSize] = {};
	int nHash;

	BloomFilter(int num_hash) : nHash{ num_hash }, filter(filter_size, false) {	
		if (num_hash > hashSize) throw "num_hash can be greater than hash size";
	}

	void hash(const email_addr& address) {	
		size_t hash_val = hasher(address.c_str());	// We have a 32 bit unsigned hash value.

		for (int i = 0; i < hashSize; i++) {
			hashValue[i] = hash_val % 256; hash_val >>= 8;
		}
	}

public:
	void insert_email(const email_addr& address) {
		hash(address);

		for (auto it = &hashValue[0]; it < &hashValue[nHash]; ++it) {
			filter[*it] = true;
		}
	}

	bool lookup(const email_addr& address) {
		hash(address);

		/*bool exists = false;
		for (auto it = &hashValue[0]; !exists && (it < &hashValue[nHash]); ++it) {
			exists |= filter[*it];
		}*/

		// Another interesting way of writing the same loop, that doesn't introduce a new temp.
		for (auto it = &hashValue[0]; (it < &hashValue[nHash]); ++it) {
			if (filter[*it]) return true;
		}

		return false;
	}
};


