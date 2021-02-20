/**
* As opposed to heaps, a binary search tree allows us to actually find an element based on the comparison
* operation.
* 
* In heaps, the children of a parent node are smaller, so we can't determine a relation in relative nodes.
* With a Binary Search Tree (BST), the right child is always greater than the parent, whereas the left child
* is lesser. This has the following consequences:
* 1- Every time we go to the left of a node (up left or down left), the node decreases.
* 2- Every time we go to the right of a node (up right ro down right), the node increases.
* 
* In this manner, we can find a node by starting from the root. If the node value is less than the value
* given, we turn right, otherwise we turn left, until we either reach null node, or the value we seek.
*/