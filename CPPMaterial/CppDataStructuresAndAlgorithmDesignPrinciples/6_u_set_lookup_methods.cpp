/**
* These methods are used for finding a particular value inside the set.
* 
* We have seen contain and find thus far, where the latter returns an iterator to the element we seek. There's also a count,
* which returns either 0 or 1 (because no duplicates are allowed).
* 
* There's another templated overload, that goes:
template< class K >
size_type count( const K& x ) const;
* This overload is used for checking if another (equivalent type) can be hashed with the same function and can be compared
* with the same equal_to method.
*/