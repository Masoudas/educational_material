/**
* First, note that when it comes to symbol tables, there was no mention of 'order' in the interfaces we just
* discussed. In other words, we don't care if keys have a natural order (we do however care that they are 
* equal comparable, because we need to check for duplicate keys. I should also indicate that in std, as said
* in the standard, regardless of whether keys have a natural order, comparison is always made with the ==
* operator.)
* 
* Second, note that with the usual symbol tables:
*	- Only one value is associated with each key.
*	- If a key is repetitive, the new value replaces the old one.
* 
* These conventions define an ASSOCIATIVE ARRAY ABSTRACTION, where we can think of a symbol table as being 
* just like an array, where keys are indices and values are array entries.
* 
* In a convential array, keys are integer indexes that we use to quickly identify values. In an associative 
* array (symbol table), keys are of arbitrary type, but we can still use them to quickly access values.
* 
* As a point of interest, if for example a symbol table has an array or list as values and we append
* new values to it, it still is an associative array. This is because each key has one and only one array,
* and not two such arrays.
*/