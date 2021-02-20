/*
* Bjarne sets these rules for passing and getting arguments in a function:
* 
* 1-	Use pass by value for small objects
* 2-	Use pass by const-ref for a large object that needn't be modified.
* 3-	Return a result as a return value rather than modifying an object.
* 4-	Use rvalue to implement move and forwarding.
* 5-	Pass a pointer if passing no-object is a valid alternative.
* 6-	Use pass by reference only if you have to.
* 
* I think perhaps 5 also applies for cases where we have collection, like for example passing an array.
* But perhaps even for those cases, passing an array class is a better alternative.
*/