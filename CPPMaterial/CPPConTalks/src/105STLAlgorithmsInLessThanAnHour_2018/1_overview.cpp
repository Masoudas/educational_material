/**
* STL library has (apparently) 105 algorithms (probably more), most of which are used to many of the every tasks
* we do, particularly with containers. They can be categorized into the following (unofficial) categories:
* 
* 1- Queries
*	* numeric algorithms (count, inner_product, accumulate/transfer(_reduce), sample, adjacent_difference, ...)
* 2- Permutations
*	* Heaps (make_heap, pop_heap, push_heap)
*	* Sort (sort, qsort, sort_heap, partial_sort, nth_element, inplace_merge)
*	* Partitioning (partition_point, partition)
*	* Other permutations (rotate, reverse, next_permutation, prev_permutation, ...)
*	* Mix of algorithms (copy_, is_*_until, stable_, *_if, *_n, is_*)
*	* Queries on two ranges (equal, lexicographical_comapre, mismatch)
* 3- Structure Changers
* 4- Value Modifiers
* 5- Movers
* 6- Algorithms On sets
* 
* This should come as no surprise to us that almost all the algorithms are in the algorithm header, but some are
* in the numeric header for example.
* 
*/