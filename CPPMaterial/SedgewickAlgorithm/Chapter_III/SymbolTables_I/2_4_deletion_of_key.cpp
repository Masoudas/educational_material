/**
* Deletion can be done lazily or eagerly. 
* 
* Lazy deletion: We associate a null-like value to deleted keys. Then, at some point in time later we remove 
* the key.
* 
* Eager deletion: We delete the key right away.
*/