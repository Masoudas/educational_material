/**
* In open addressing hash tables, we first look inside the placement of the hash value. If this place is
* empty, we place the item there. Otherwise, we place the item at an offset of the given hash. The offest
* can be:
* 
* 1- Linear: If the hash location is full, then place the element at hash + 1, then if that place is full, 
* then place it hash + 2, etc.
* 2- Quadratic: Same as linear, except we choose 1^2, 2^2, 3^2, ...
* 
* Note that when it comes to finding the elements with this strategy, we need to have loop. So if the place of
* the hash is empty, we say that the element does not exist. Otherwise, we have to check for equality in the
* place of hash and if it's unequal, we need to check hash + 1, hash + 2, etc. So, the find method has order
* O(n) in the worst case. Put this together with the fact that insertion potentially has a cost of O(n) as well,
* we conclude that avoiding collision comes at the cost of increasing computational burden.
* 
* Note also that if data is densly clustered (meaning if many instances around the same hash value), this
* method is particularly inefficient.
* 
*/
