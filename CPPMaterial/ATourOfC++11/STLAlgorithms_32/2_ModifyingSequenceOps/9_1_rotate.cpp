/**
*	-	constexpr ForwardIt rotate( ForwardIt first, ForwardIt n_first, ForwardIt last );
* 
* Me: n_first stands for new first.
* 
* Performs a left rotation on a range of elements. Specifically, std::rotate swaps the elements in the range 
* [first, last) in such a way that the element n_first becomes the first element of the new range and 
* n_first - 1 becomes the last element.
* A precondition of this function is that [first, n_first) and [n_first, last) are valid ranges.
* The algorithm is particularly interesting. See below:

template<class ForwardIt>
ForwardIt rotate(ForwardIt first, ForwardIt n_first, ForwardIt last)
{
   if(first == n_first) return last;
   if(n_first == last) return first;
 
   ForwardIt read      = n_first;
   ForwardIt write     = first;
   ForwardIt next_read = first; // read position for when "read" hits "last"
 
   while(read != last) {
      if(write == next_read) next_read = read; // track where "first" went
      std::iter_swap(write++, read++);
   }
 
   // rotate the remaining sequence into place
   (rotate)(write, next_read, last);
   return write;
}

Explainantion: The rotation becomes a cyclic affair once n_first until last has been moved to its location,
in that whereever old first goes, we have to start from there and change from the element after the last
changed value.
Or, imagine  k < N/2. Then the first cyclic shift leads to:
x_k,...,x_(2k-2),x_(2k-1),...,x_N,x_(l+1),...x_k-1,x_1,...,x_l
And we can see that we need another cyclic shoft from new position of x_1 with x_(l+1) which was the last read.

The challenge of understanding these algorithms is to understand the indirection to the underlying element.
We swap elements, and not iterators. 

*
*/
