/**
* Two notions are essential when it comes to template metaprogramming:
* -	lifting:  generalizing an algorithm to allow the greatest (reasonable) range of argument types, that is, to 
*	limit an algorithm’s (or a class’s) dependency on properties to what is essential.
* 
* - concept: carefully and precisely specifying the requirements of an algorithm (or a class) on its arguments.
* 
* Regarding lifting, the big guy always states that we should solve a problem for a particular type in mind, and'
* then try and lift it. This is very true, and I've seen on several occasions when I try to solve all stages of a
* problem together (thinking about the algorithm, operations, and then generalization) I lose everthing together.
* Therefore, it's good practice to first implement an algorithm, and then lift it.
* 
*/