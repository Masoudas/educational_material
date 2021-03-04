/**
* First, note that when it comes to symbol tables, there was no mention of Order in the interfaces we just
* discussed. 
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
*/