package MyRandomProblems.Counting;

/**
 * So imagine we have an array of size N. Now we cut it from the middle. How many elements are
 * on either side? Assume array indexes start from zero.
 * 
 * If the array size is even, then N/2 is the element after middle N/2 - 1 |middle - no element| N/2.
 * Hence, there are N/2 - 1 elements after N/2th element [N/2 , ... N-1], and N/2 before it [0, ... N/2 - 1].
 * 
 * If N is odd, assumong we remove after decimal, N/2 is before middle. Now, we have N/2 - 1 elements
 * before it and N/2 - 1 after it. So to get consistency with the previous case, it's always best to 
 * write N/2 + 1 (or ceil(N/2)).
 * 
 * 
 * Now imagine, we merge this array from the middle index into another array, say at index i (assume array is properly set.)
 * Now, what is the index of first element and last element?
 * 
 * So, essentially we have shifted the center of the array to element i (remember the rabbit!). Hence, because element ceil(N/2)
 * is at i, we have shifted the entire array by i - ceil(N/2). Hence, the zeros element would be i - N/2, and the last element would
 * be at N - N/2 + i = N/2 + i;
 */