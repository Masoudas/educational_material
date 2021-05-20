/**
* A string can be cleared in two different ways:
*	-	Using the clear method
*	-	Setting it to empty string
*		Note that by this we mean str = "", and not str = " ", because the latter is actually meaningful.
* 
* A set of benchmarks actually show that the clear method work much more efficiently than setting the string
* equal to "". Hence, we better use this method!
*/