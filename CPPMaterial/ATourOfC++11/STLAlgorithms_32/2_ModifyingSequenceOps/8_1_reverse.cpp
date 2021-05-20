/**
* Me: Seriously, most of the fundamental operations I can think of are implemented by the standard library.
* 
*	-	constexpr void reverse( BidirIt first, BidirIt last );
* Reverses the order of the elements in the range [first, last).
* Behaves as if applying std::iter_swap to every pair of iterators first+i, (last-i) - 1 for each non-negative 
* i < (last-first)/2.
// Important implicit point regarding implementation! first and last should not be changed together then
// compared! As if iter_swap(first++, --last). If first is equal to last or one after it, we're done!
template<class BidirIt>
void reverse(BidirIt first, BidirIt last)
{
    while ((first != last) && (first != --last)) {
        std::iter_swap(first++, last);
    }
}

*/