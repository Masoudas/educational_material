/**
* The 'rank' operation in STs determine how many elements are below a particular key (me: essentially the 
* number of keys less than the given key with the given comparison method).
* 
* The select operation selects a key with the given rank.
* 
* As a reminder, note that because we don't have duplicate keys, each key has a unique rank. Therefore, 
* selection based on rank is the same as indexing in an array, and it returns the unique key-value associated
* with that rank. Consequently, we can write for key 'k' with rank 'r':
* 
* r == rank(select(r));
* k == select(rank(r));
* 
* For symbol tables, our challenge is to perform these operations quickly, intermixed with insertions, 
* deletions, and searches.
* 
*/