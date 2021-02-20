/**
* This time around, assume we've violated the condition from the parent, i.e, a parent is smaller than
* one or two of its children. Then we need to find the larger child, replace it there, and then migrate
* to that child node, and repeat the condition. This operation is called a sink, and the code is
* given below.
* 
* We may think of sink as when a new manager is introduced to a company. We expect the manager to sink
* until he's higher than the people below him. 
* 
* It's very important to note that in the following, n is the size of the pq array, not the size of the heap.
* 
// Assume that the array od nodes is called pq. Assume also that we have n nodes.
// Ugly implementation I:
void sink(int k){
	while (2 * k < n && (pq[k] < pq[2k] || pq[k] < pq[2k + 1])){
		if (pq[2k] < pq[2k + 1]){
			swap(pq[2k + 1], pq[k])
			k = 2*k + 1;
		} else {
			swap(pq[2k], pq[k])
			k = 2*k;
		}
	}
}

// Implementation II: Note that if we get the biggest child node first, everything becomes simpler.
void sink(int k){
	while (2 * k < n){	
		int i = 2k
		if (i < n && pq[i] < p[i+1]) i++; // Note that i < n means we ensure that the node has two children! (n-1
										  // is last child.	
		if (pq[k] > pq[i]) break;	// If we didn't put the break here, we'd get over children unnecessarily!
		swap(pq[k], pq[i]);
		k = i;
	}
}

*/