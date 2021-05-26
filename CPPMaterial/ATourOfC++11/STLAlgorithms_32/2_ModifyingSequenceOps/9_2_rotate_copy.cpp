/**
* As we may recall, the methods ending in copy generate a copy collection of the original collection. Rotate
* copy rotates a collection, but at the same time, puts it in a new collection. The implementation is actually
* quite simple:

template<class ForwardIt, class OutputIt>
OutputIt rotate_copy(ForwardIt first, ForwardIt n_first,
                           ForwardIt last, OutputIt d_first)
{
    d_first = std::copy(n_first, last, d_first);
    return std::copy(first, n_first, d_first);
}

*/ 