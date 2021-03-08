/**
* Before we delve into the implementation of STs with sorted arrays, let's consider the binary search. In
* particular, suppose an array is sorted, we're interested in a rank-based binary search, where:
* 
* 1-	If an element actually exists in the tree, we return its index
* 2-	If an element does not exist, we return the index of the last item less than it.
* 
* Where 2 works because the array is sorted. Hence, in an array like [1, 2, 3, 5], the rank of 2 is 2, whereas
* the rank of 4 is also 3.
* 
* Perhaps we could think of binary search as follows. The goal is to find the interval of size two for which 
* the first element is always smaller and the last elemnt is always greater than the item we search. 
* 
* Recall that mostly it's best to implement a recursive version first, we start by considering lo and hi. We
* consider the middle element of the array, and move lo to that position if mid is less than the key we search
* for, or bring hi there if mid is greater than the key. It's clear that in this schema, lo never decreases.
* Now, suppose that we have two elements left. The next possible case is that either lo increases and equals
* hi, or vice versa. Hence, the termination condition is that hi >= lo. On the other hand, we may get lucky
* and mid equals the key we're searching for, in which case we stop the algorithm right away. 
* 
* Any consideration should be given to how we calculate mid? mid can fall the one below or after middle, but
* it really doesn't matter. We're only interested in whether or not an element in the middle is less, greater
* or equal to our value.
* 
* A typical mistake that I make regarding these algorithms is this. I say Ok, was the previous high greater
* than or less than the value. So if this high is less and the previous was greater, now we're where we should
* be. This is only applicable in a sequential search, when start from the right and go back an element every
* time.
* 
* With that being said, below we provide an implementation of such binary search algorithm, under the name
* rank.
* 
* Note: The implementation in the book is wrong, when it says if (key < mid) rank(key, mid + 1, hi). Suppose
* [1,2,4,6] and we search for 5. Then mid = 2 and (4 < 5) and now lo = 3. However, rank is supposed to be
* two. The given implementation is correct if we were searching for an actual value, and not the leftmost
* value.
*/

template <typename Key, typename Val>
struct st {
	Key* keys;

	int rank(const Key& key, int lo, int hi) {
		if (lo > hi) return lo;	// We should say here that hi == lo, but if we start from the wrong indexex
								// we should punish the client!
		int mid = (lo + hi) / 2;

		if (key < keys[mid]) {
			return rank(key, lo, mid - 1);	// Because the mid is greater, we save some time by going to the
											// previous element.
		}
		else if (key > keys[mid]) {
			return rank(key, mid, hi);
		}
		else {
			return mid;
		}
	}
};