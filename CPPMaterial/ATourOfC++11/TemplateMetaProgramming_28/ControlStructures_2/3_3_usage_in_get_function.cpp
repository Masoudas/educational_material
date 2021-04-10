/**
* An interesting usage of select is in the get function for tuples, which we recall is used for getting the nth element of
* a tuple. Such a function has the following syntax (suppose t is a tuple instance):

template<int N, typename T1, typename T2, typename T3, typename T4>
Select<N,T1,T2,T3,T4> get(Tuple<T1,T2,T3,T4>& t); 

auto x = get<2>(t); // assume that t is a Tuple

* Here, the type of x will be whatever T3 is for the Tuple called t. Indexing into tuples is zero-based.
* 
* Note: It appears in the definition of the get method in C++20, they've used the same strategy as the variadic arguments,
* but with ranges library of C++20. I need to work on those as well.
*/

