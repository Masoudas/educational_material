/**
* As always, there are several overloads for the constructor. 
* 
* - explicit unordered_set( size_type bucket_count, const Hash& hash = Hash(), const key_equal& equal = key_equal(),
*	const Allocator& alloc = Allocator() );
*	In this constructor, the bucket size is predefined.
* 
* - We can supply a begin an end iterator to create a new set from an iterable collection.
* - There's a copy constructor and copy constructor with allocator.
* - Finally, there's an initializer list as well.
*/