/**
* In simple terms, an unordered_set uses hash functions together with chaining to create the hash table.
* When the load factor reaches one, a major rehashing is done. Each bucket has a list to support chaining.
* 
* By default, unordered set and map containers have a maximum load factor of 1. As soon as the number of elements 
* exceeds the size of the hash table, the hash function will be changed, the hash values will be recalculated 
* (rehashing), and a  larger hash table will be rebuilt to bring down the load factor. We can also use the rehash 
* function to do this manually. This default maximum limit of 1 for the load factor can be changed using the 
* max_load_factor(float) function. The values will be rehashed once the load factor exceeds the defined maximum 
* limit.
* 
* The standard says:
* Unordered set is an associative container that contains a set of unique objects of type Key. Search, insertion, 
* and removal have average constant-time complexity. Internally, the elements are not sorted in any particular 
* order, but organized into buckets. Which bucket an element is placed into depends entirely on the hash of its 
* value. This allows fast access to individual elements, since once a hash is computed, it refers to the exact 
* bucket the element is placed into.
* 
* The important point when working with sets and hash tables as always is that the elements should not be modified,
* even by non const iterators. Otherwise, the hash table is corrupted.
* 
* The class template type is as follows (there's also an equivalent pmr version):

template<
    class Key,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator<Key>
> class unordered_set;

* Question: Why do we need an equal_to method then? This will become important when we want to create a set of
* custom types? Aha! Remember that after all, a set must not contain any duplicate elements. If two elements have the
* same hash, then inside a bucket, we need to check whether they're equal or not, which is done using the equal_to
* functional.
* 
* The standard also groups the methods associated with the set as follows:
* Iterators: (c)begin and (c)end;
* Capacity: empty, size and max_size
* Modifiers: clear, insert, emplace,  emplace_hint, erase, swap, extract, merge
* Lookup: find, count, contains, equal_range
* Bucket interface: (c)begin, bucket_size, bucket_count, bucket.
* Hash policy: load_factor, max_load_factor, rehash, reserve
* Observers: hash_function, key_eq
* Non-member functions: operator==, erase_if, std::swap  
* 
* The set is called unordered, because the elements have no particular order when they're put inside the set.
* If we want a set that has order (of how elements are put), we should use ordered sets.
*/