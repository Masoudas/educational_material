/**
*	-	constexpr ForwardIt rotate( ForwardIt first, ForwardIt n_first, ForwardIt last );
* 
* Me: n_first stands for new first.
* 
* Performs a left rotation on a range of elements. Specifically, std::rotate swaps the elements in the range 
* [first, last) in such a way that the element n_first becomes the first element of the new range and 
* n_first - 1 becomes the last element.
* A precondition of this function is that [first, n_first) and [n_first, last) are valid ranges.
* 

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

*
*/
???