/**
* Binary heap: An array, where each key is guaranteed to be greater than two other keys.
* 
* Heap Ordered Binary tree: A binary tree is heap-ordered iff every node is greater than
* equal to it's children (if any).
* 
* In heap ordered binary tree, the largest node is at the top. This is because it's greater than
* it's childers, which are greater than their children, and so forth.
* 
* Note that if we consider any node of binary heap, all its children are smaller. With two children node, 
* if a > b, then all children of 'b' are smaller than 'a' too. However, children of 'a' can or cannot be 
* smaller than b. Consider [- 10 9 7 8 6 5] 8 is a child of 9, but it's greater than 7. 5 is a child of 7, 
* but it IS smaller than 9.
* 
* Complete binary tree: I guess a tree where we fully fill one level before moving to next.
* We represent such a complete tree of N nodes with an array of N+1 elements, where 0 is left unused.
* We index the nodes from 1. Hence, the index at level k is twice the index at level k-1. This way, the
* children of node l will be 2l and 2l+1, and parent of node l will be floor(l/2).
* 
* In this scheme, the index of the right most level of each node is always an odd number. If a tree has
* k levels, we know that it has 2^(k+1)-1 nodes, where the indexes of the last level start from 2^k to 2^(k+1) - 1,
* Hence, each level has 2^k nodes.
* 
* Such a tree has a height of log(N), which we can prove by induction.
* 
*/

