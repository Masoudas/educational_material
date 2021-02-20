/** 
* The goal of bottom up reheapify is to move a larger key up the hierarchy. We can do this by comparing it to its
* parent, and then moving it up. This operation is known as swimming.
* 
* When we replace a node with its parent, we already know that the third node was smaller than the parent. Hence,
* replacing a larger node with the parent does not ruin the binary heap structure.
* 
* We can think of swimming as when a subordinate gets better than the boss in a hierarchy. Then that 
* subordinate moves up the hierarchy until being lower than a boss.
* 
* The code for this operation is given below:
* 
// Assume the array is called pq. Moreover, assume that we have exactly n nodes.
void swim(int n){
	
	while ( n > 1 && pq[n/2] < pq[n]){
		swap(n/2, n);
		n /= 2;
}
*/