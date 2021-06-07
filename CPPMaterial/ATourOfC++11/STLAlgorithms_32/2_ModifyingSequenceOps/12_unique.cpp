/**
* Me: This is exactly like the unique method of the vector, and removes equivalent consecuitive element. Because actual
* deletion is impossible, moves elements. Don't forget to possibly call the container's erase method after.
* 
* Me: Naturally, the binary predicate is supplied to compare two consecutive elements.
* 
*	-	constexpr ForwardIt unique( ForwardIt first, ForwardIt last );
*	-	constexpr ForwardIt unique( ForwardIt first, ForwardIt last, BinaryPredicate p );
* 
* Returns iterator to the end of the new unique container.
* 
* Removing is done by shifting the elements in the range in such a way that elements to be erased are overwritten. 
* Relative order of the elements that remain is preserved and the physical size of the container is unchanged. Iterators 
* pointing to an element between the new logical end and the physical end of the range are still dereferenceable, but the 
* elements themselves have unspecified values. A call to unique is typically followed by a call to a container's erase 
* method, which erases the unspecified values and reduces the physical size of the container to match its new logical size.

Result holds pointer to what is going to be returned. For every element that is unequal to current itr, a move takes place.
Otherwise, we go past the element, and then move takes place once we have an equal element. ++result != first is for not
moving this element into itself.

ForwardIt unique(ForwardIt first, ForwardIt last)
{
    if (first == last)
        return last;

    ForwardIt result = first;   
    while (++first != last) {
        if (!(*result == *first) && ++result != first) {
            *result = std::move(*first);
        }
    }
    return ++result;
}

*/