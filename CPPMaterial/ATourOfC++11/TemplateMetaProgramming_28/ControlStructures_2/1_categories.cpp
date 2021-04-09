/**
* To do general computation at compile time, we need selection and recursion.
* 
* The big guy says: "In addition to what is trivially done using ordinary constant expressions, I use: 
*	- Conditional: a way of choosing between two types (an alias for std::conditional)
*	- Select: a way of choosing among several types 
* 
* These type functions return types. If you want to choose among values, ?: is sufficient! Conditional and Select are for 
* selecting types. They are not simply compile-time equivalents to if and switch even though they can appear to be when 
* they are used to choose among function objects (me: For one thing, they can have multiple returns.)
* 
* Note from me: I shall be using _v or _t aliases instead of raw function types the big guy uses here, because they
* weren't introduced in C++11.
*/