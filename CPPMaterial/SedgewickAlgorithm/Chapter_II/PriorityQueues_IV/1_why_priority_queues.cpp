/**
* Often, we want analyze some keys, in the sense of finding the largest item, and working with that. Then 
* add more keys, find the largest, and work with that. For example, an incoming call in a phone has a high
* priority and if added to the list of programs, it should be found and executed first.
* 
* Moreover, often we don't have access to the full data. We only have a subset of it. As we add more data, 
* we want to do some analysis, again possibly on largest item.
* 
* An appropriate data type in such an environment supports two operations: remove
* the maximum and insert. Such a data type is called a priority queue. 
* 
* A priority queue hence is like a normal queue, except that everytime we move the top element, we remove the 
* highest element (in some sense) and not the first element.
* 
* Priority queues can be used as sorting algorithms too, where we put items in, and start to extract from 
* the smallest to get the order.
*/