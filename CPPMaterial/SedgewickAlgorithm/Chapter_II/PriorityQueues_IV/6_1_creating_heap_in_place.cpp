/**
* One solution to creating the heap for a given array is to start from the left position of the array.
* Assuming that this is the top element, then put element two in place of one, and then sink. 
* While this is a good approach and takes NlogN time, a better one can be proposed as follows.
* 
* Instead of starting from left, start from right. Now, we know that if we have N elements in an array,
* then half the elements of array ([N/2]+1) will be leaves in a heap. Hence, skip the first N/2 elements.
* Now, for each element in the remaining, do a sink. This way, we create partial heaps, and we connect them
* from bottom up.
* 
* Now the question is, how many exchanges do we need? 
* Solution I: Note that a node at height k is going to be exchanged with at most logN - logk nodes. Consequently,
* starting from the first node, we have 1 * h + 2 * (h - 1) + 4 * (h - 2) + ... + N/4 * (h - h - 1), where h is the height
* of the tree. An addition of N/2 * ( h - h ) leads 2 ^ (h + 1) - h - 2 = N - h - 1 <= N 

* Well, as we discussed in MyRandomProblems/IndexingProblems/NumberOfNodesInATree, the level before the last
* level of the tree has a quarter of Nodes, and they require 1 exchange. Then the level before that 1/8, and they
* require 2. Hence, we can write N/4 + N/8*2 + N/16*3 +... 1*logN. Now, instead of solving this, we note that
* we can approximate it with an infinite series, which is less than 1. Hence, the sum is less than equal N.
* 
* Note that with the same reasoning, we can argue that the total number of comparisons is 2N.
*/