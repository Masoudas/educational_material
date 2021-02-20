/**
* Assume that we're working with a system of k bits.
* 
* How to calculate two's representation of x >=0? Divide by 2. Then from right to left, the first
* quotient, to first remainder. Why? Because n = 2 (2*n+1) + q, and so on, where q is the remainder of first division.
* 
* What about fractions? We know that n = 2^-1c_1 + 2^-2c_2 + 2^-3c_3 + ..., then 2n = c_1 + ..., so first digit
* is derived this way. Then 2n-c_1 = 2^-1c_2 + ... and we move forward.
* 
* To calculate the two's complement, calculate one's complement of each bit, then add one.
* 
* What's x (say x=1000b) two's complement of? Go one bit ahead, then add. Here 2^k+1 - x. Why? Because 
* x + -x = 2^(k+1).
* 
* The point about two's complement is that addition, subtraction, multiplication and division can be done with it.
* 
* For example, if x, y <0, then x + y = 2^k+1 - x + 2^k+1 -y. However, x + y = 2^k+1 - (x+y), because the k+1 bit is
* ignored. Then, we can see that x+y is equivalent to its two's complement. Multiplication can be proven assuming
* several addition.
* 
* Regarding division, first consider division by two. Assuming x < 0 Then x >> 1 is 2^k - x >> 1. But then,
* 2^(k-1) - x/2. At this point, we see that to derive the two's complement of x/2, we need to add 2^(k-1) to this number.
* Hence, we just need to add the sign bit. What about division by 4? then we have 2^(k-2) - x/4. Hence, we need to add
* 2^(k-1) + 2^(k-2) to this number to get the two's complement of x/4. 
* So what is the conclusion here? If we want to do the division for a negative number, when we shift right, 
* we have to replicate the sign bit!!! In fact, CPUs have Arithmetic Right Shift (ARS) and Logical Right Shift (LRS). 
* The arithmetic shift takes care of the division, whereas logical shift takes care of logical right shift.
* 
* What about division by nonmultiples of two? I don't know how it's done. The point is that x/l still is 2^k+1/l - x/l.
* 
*/