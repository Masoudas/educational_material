/**
* As we already know, a tree has at most [logN] depth.
* 
* Here's a question: How many nodes are there at the deepest level of the tree?
* To answer this, note that the number of nodes at each level of the equals the TOTAL number of nodes of all
* previous levels plus one!!! 
* 
* Why is this the case? Because when we double the number of nodes at a new level, then all the nodes of the previous
* can be put into it, then we still have half the space for the previous level and so forth (like with 4 nodes,
* we have space for 2, and 1, and one space left). This observation comes from the fact sum_1^k-1 = 2^k+1 -1.
* Now, consider a tree. We know that its last level has as many levels as the previous nodes of the tree. Hence,
* if we divide total number of nodes by 2 (or N/2), then [N/2] are on the previous nodes, and [N/2]+1 are at the last 
* level (because last level is previous levels plus 1). 
* 
* Now, what is the index of the first element of the last row, assuming starting from 0? It would be [N/2], because
* 0 to [N/2]-1 are before the last depth. This is exactly like cutting an array in half.
* 
* Now, how many nodes are at the level prior to last? We know that a quarter minus one go there. Hence [N/4] + 1
* would be there. Of course, generally, we know that there are 2^k nodes at level k.
* 
* And of course here, we arrive at the conclusion that N/2 + N/4 + ... N/[logN] = N. In other words, cutting a 
* chocolate in half, then the other half in half, lead us to the full chocolate.
*/