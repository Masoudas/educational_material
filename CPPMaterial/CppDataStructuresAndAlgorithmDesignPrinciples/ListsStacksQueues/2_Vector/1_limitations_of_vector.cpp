/**
* Vectors have the following limitations:
* 
* 1- Size of vector has to be specified at compile-time.
* 2- Due to size limitations, we can't insert or remove elements from the array.
* 3- No custom allocation is possible for std::array. It always uses stack memory
* 
* On the last one and for my piece of mind, if I created an array on the heap, would its content still
* be on the stack? Or in general for a class? It does sound reasonable to assume that an object created
* on the heap has its data on the heap. The book says it always uses stack memory though.
*/