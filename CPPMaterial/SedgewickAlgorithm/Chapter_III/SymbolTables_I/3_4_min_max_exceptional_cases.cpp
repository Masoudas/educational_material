/**
* Imagine that there's no min or max for the given symbol table. How would we deal with such a situation?
* Well for example in C++, there are no such methods, and we need to find min and max in other ways (iterators
* are the perfect way to do so.) Now, if we use iterators, then they'd point to end, and our task is complete.
* However, in the implementations we do here, we throw exceptions for such cases.
*/