"""
These represent finite ordered sets indexed by non-negative numbers. The built-in function len() returns the number 
of items of a sequence. When the length of a sequence is n, the index set contains the numbers 0, 1, …, n-1. Item i 
of sequence a is selected by a[i].

Sequences also support slicing: a[i:j] selects all items with index k such that i <= k < j. When used as an 
expression, a slice is a sequence of the same type. This implies that the index set is renumbered so that it starts 
at 0.

Some sequences also support “extended slicing” with a third “step” parameter: a[i:j:k] selects all items of a with 
index x where x = i + n*k, n >= 0 and i <= x < j.

Sequences are distinguished according to their mutability
"""