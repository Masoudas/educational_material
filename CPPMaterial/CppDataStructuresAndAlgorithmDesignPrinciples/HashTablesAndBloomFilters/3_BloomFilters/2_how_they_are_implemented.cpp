/**
* Implementing a bloom filter is simple. We use three distinct hash functions, together with an structure that
* can hold boolean values (like each bite of an int, or an array of bools). Now, each time a new value is inserted
* in the data structure, we compute the hash with the three values, and set the corresponding bits equal to true.
* 
* When we want to check whether a data exists, we compute the hash value and check whether all three corresponding
* bits are true.
* 
* Naturally, the hash function must not give back values that are outside the number of bits. For example, a module
* 8 hash function means we can have only eight bits (or a char) holding the data.
* 
*/