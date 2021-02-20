/**
* Note that some operators can only be NON-STATIC member functions. These include operator=,
* operator(), operator[] and operator->(). We can't overload these operators as free functions
* (me: which make sense, because we have to use them with types, saying a[] or a()).
*/