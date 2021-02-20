/**
* When passing objects to an overloaded operator, we don't pass or return pointers for several reasons,
* the most important of which is that we don't want to pollute the expression (imagine *a= d + &c).
* (Also note that passing by reference may not be possible, as discussed in 10).
* 
* So our only viable options are:
*	-	Pass by value.
*	-	Pass by reference (l or r).
* 
* We tend to pass by value when the object is less than a couple of words, and pass by reference when the
* object is big. In particular, we normaly pass as const reference to indicate no change to the passed 
* reference.
*/