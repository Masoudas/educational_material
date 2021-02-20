package Chapter2.ElementarySorts_1;

/**
 * An inversion in an array is a pair that is out of order in an array. For example AB has no inversion,
 * whereas BA has one. BAC has one, BA, whereas CAB has tw, CA and CB.
 * 
 * We say that an array is partially ordered, if the number of inversions in it is less than a constant multiple of
 * the array size (What now, why a constant multiple?)
 * 
 * For example, ABC is partially ordered. BAC is partially ordered 1 < 3, and I guess so is CAB (2 < 3). 
 * But what about CBA? Because 3 == 3, but 3 < 6!!
 * 
 * Typical examples of partially sorted arrays are:
 * 1- A small unordered array attached to a sorted array.
 * 2- An array where every element is not far from its final position.
 * 3- A sorted array, with a few unsorted ones.
 * 
 * Insertion array is very efficient for patially sorted arrays, and it's likely to be faster than any other sorting
 * algorithm.
 * 
 * So look. Suppose we have 132. If an inversion is adjacent, we need one inversion to make it ordered.
 * However, if they're far away, like 312, each comparison detects at most one inversion, and each exchange cures at most
 * one inversion. This is obvious, because it does not affect the order relative to previous or next elements. Hence,
 * we have the following proposal:
 * 
 * Proposition: The number of exchanges in insertion sort equals number of inversions in the array.
 * Proof: Every exchange is done for the purpose of removing one inversion. Hence, the number of exchanges and inversions
 * have a one to one correspondence. If there were no inversion, there would be no exchanges.
 * 
 * Proposition: The number of compares is at least the size of the array minus one, or
 * at most the number of inversions plus array size plus one.
 * Proof. If there are no inversions, the array is ordered, and we need N - 1 compares, and the proof is complete.
 * Evey exchange requires one compare, and an additional one, until the element reaches the left of the array.
 * 
 */
