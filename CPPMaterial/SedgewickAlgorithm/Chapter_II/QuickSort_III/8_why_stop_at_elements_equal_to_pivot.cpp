/**
* As we can see with quicksort, we're supposed to stop if the pivot equals a key, and then exchange.
* Why not just step over such keys?
* 
* This is because we actually prefer the j index to finish higher than lower. So imagine if we had an array
* like [1, 2, 1, 1, 1, 1, 2, 2]. If we didn't stop at equal keys, then j=i=1, which would mean that the next sort
* will start at i=1. Whereas the situation would have improved if we stopped at equal key j=5, and exchanged.
* 
* The higher the j index stops, the closer it gets to the NlogN.
* 
* In fact, if an array has equal keys, then with the current implementation we approach NlogN. However, if this
* weren't the case, we'd need N^2 comparisons.
* 
* In conclusion, always stop for the equal elements.
*/