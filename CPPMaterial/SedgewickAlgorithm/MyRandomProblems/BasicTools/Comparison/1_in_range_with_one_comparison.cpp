/**
* So, if we wanted to check whether an integer is in a particular range, we can do it using two comparisons,
* saying x > low && x < high.
* 
* It's however possible to do this using one comparison as well, saying (x - low) * (high - x) > 0. Hence for
* example, for x = -1 and [-2, 0] we have (-1 + 2) * (0 + 1) > 0 holds, however, for x = 1 we have 
* (1 + 2) * (0 - 1) < 0.
* 
* Question: Does it work for unsigned values? Nope. x - low becomes a large positive integer.
* 
* Another solution is to note that (x-low) <= (high-low) must always hold.
* 
* Question: Does this solution for unsigned numbers also? The only worrysome range is when x < low. In this case,
* x - low results in underflow upon comparison, leading to a very large value. But it's still a possiblity that
* this comparison will fail.
* 
* In conclusion, the second solution is dangerous for unsigned values, though ok for signed values. The first
* solution is 
*/