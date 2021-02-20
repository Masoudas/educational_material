/**
* As we already know, array and vector iterators are random access and most flexible, whereas forward_list
* iterators are very rigid. list iterators fall in the middle, in the sense that they allow increment and
* decrement, but they don't allow random access. In this sense, they're bidirectional, but not RA. We have
* the following inequality hence:
* 
* forward_list::iterator < list::iterator < vector::iterator.
*/