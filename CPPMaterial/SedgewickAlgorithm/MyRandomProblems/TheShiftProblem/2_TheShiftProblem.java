/**
 * Shifting is something I have a lot of problems with.
 * 
 * Let's start with integer manifestation. Say I want to extract the 8th bit of an integer (32 bits).
 * What do I do?
 * 
 * Ok, let's think of it as bugs bunny. Each jumb bugs makes, moves him one place. Hence, from zero
 * to one takes him ONE JUMP. So from fifth place (his current position) to the eight place (the position he wants
 * to be) takes him three jumps. Why is this so hard for me to understand? From tenth to twentieth requires ten jumps.
 * 
 * Now, note that 0x0001 has a one at the zeroth or first place. If we say zeroeth, it takes eight jump to get
 * to the eight place. The same is true for first place. Hence, we need eight jumps of course.
 * 
 * 
 * Let's assume that I'm at the n-th position in the array, and I want to get to the k-th position. How many jumps
 * do I need? The answer is k - n. Hence, I need to increment k - n times. If n > k, then I need to decrement n - k times.
 */