/**
* STL library has (apparently) 105 algorithms (probably more), most of which are used to many of the every tasks
* we do, particularly with containers. They can be categorized into the following categories:
* 
* 1-	Search
* 2-	Query 
* 3-	Sort
* 4-	Counting
* 5-	Manipulation
*
* This should come as no surprise to us that almost all the algorithms are in the algorithm header, but some 
* are in the numeric header for example.
* 
* Note that for each algorithm, there's a constrained version in the ranges library. The documentation says
* "In these algorithms, a range can be specified as either an iterator-sentinel pair or as a single range 
* argument, and projections and pointer-to-member callables are supported. Additionally, the return types of 
* most algorithms have been changed to return all potentially useful information computed during the execution 
* of the algorithm."
* 
* As an example of a constrained algorithm:
std::vector<int> v = {7, 1, 4, 0, -1};
std::ranges::sort(v); // constrained algorithm
std::sort(v.begin(), v.end());	// me: non-constrained old-fashion algorithm!
* 
*/