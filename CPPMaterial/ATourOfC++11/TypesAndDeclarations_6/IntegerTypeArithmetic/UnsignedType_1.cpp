/**
So here's the deal. 

If an unsigned integer type (including char) overflows, the results is module 256.
char c = 255;
c++;
std::cout << (int)c;    // prints zero.
Why is it the case? Because the result is promoted to int. And then this int is implictly casted back to char.

unsigned types round, if a negative value is assigned to them, or the result
of an operation is negative. In other words, in case of overflow, the result would be 2^w modulo of that negative number 
(or 2^w - x). This would be called underflow by the way.

For example:

unsigned int x = 0; x--; // x would be 2^33-1 I guess. 

It's generally unwise to use unsigned types, especially when it comes to loops.

This is the nature of all unsigned arithmetic in C++. This as we may guess, might lead to
catastrophic consequences.


Now. Imagine we have an array class, and we want to iterate over it in reverse direction.
Now, one might write the loop like this:
for (auto n = arr.size(); n >= 0; --n){
	// Do something here.
}

The problem with this code is that n will never be negative!! Hence, as we get to 0, n-1 would be 2^32-1 (assuming 32 bit).
Hence, we need to write this in one of the following manners:
for (auto n = arr.size(); n != 0; --n){
	// The index would be n-1. Now we terminate the loop.
}

Or this solution:

int n = arr.size();
while(n){
	
	--n;
}

As another example, consider this scenario:
for (unsigned i = 0; i < nlengths; i++) {
        unsigned candidates = total - lengths[i] + 1;
        for (unsigned j = 0; j < candidates; j++) {
            // use j as an array index

Here, if total + 1 is less than length[i], then candidates would be negative. Hence, the number would be 2^w-candidates, and 
all of a sudden we're having a loop of billion times.

As another example, imagine we want to access an array. So we set the check for an int:
if (n < 0 || n >= x.size())
      throw an out-of-range exception;
// Now it is safe to access x[n]
If n is greater than x.size(), there's no problem, If n however is negative, because we're compaing unsigned with signed,
we promote unsigned to singed. Hence, n might actually fall in range! However, the first check saves us here. So I think this is good!


We also have this example, assuming char is 8 bits:
for (char c = 0; c < 300; c++)
Whether c is signed or unsigned, it will never achieve 300. Hence, this loop runs for ever.
*/

/**
 * As another example, say how many times this loop is repeated? */
void how_many_times_loop_is_repeated(){
      unsigned char half_limit = 150;

      for (unsigned char i = 0; i < 2 * half_limit; ++i)
      {
      // do something;
      }
}

/**
 * The answer would be infinite. This is because 2 * half_limit is promoted to int. Hence, i is also promoted to int.
 * However, after it reaches 255, another increment sets it to 0. Hence, this loop is repeated infinitely.
 */

