/**
So we have the following code for generating primes until n. The algorithm is follows:
sqrt(n) is the greatest number that can divide n.
For any number below this number (except for zero and one), remove all multiples of any
number less than sqrt(n) (for example 2 * 2, 2 * 3 ... or 3 * 2, 3 * 3 ...)
The numbers that remain are all primes.

Why does this work? Because any number below sqrt(n) can possibly divide any value between sqrt(n) and n. hence,
when we remove all multiples of any number below sqrt(n), we've removed all multiples (all non-prime numbers). Hence
the only ones that are remaining are primes.