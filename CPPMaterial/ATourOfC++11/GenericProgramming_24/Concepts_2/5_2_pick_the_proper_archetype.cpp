/**
* When choosing your (bloody!) archetype, we must be careful to choose a type that fits the bill of the desirec
* concept perfectly, and does not provide more flexibility. 
* 
* For example, for the find method discussed previously, a common mistake is to provide the iterator of a vector.
* However, this is wrong, because a vector's iterator is a random access iterator, and not a forward iterator, 
* which is more flexible. Therefore, we wouldn't be able to catch the error discussed in the find method. Finally,
* if we can't find a type that fits the bill for what we desire, we have to define our own type.
* 
* 
*/