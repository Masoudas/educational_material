/**
* We must think of conditions as predicates. For example, T must have < operator. T must be copiable.
* Then a function that takes type C, and checks for the predicate must be defined.
* 
* A predicate as such on a template is called a CONCEPT.
* 
* For example, if template T should be a container we can say:
* 1-	T must have a subscript operator ([]).
* 2-	T must have a size() member function.
* 3-	T must have a member type value_type which is the type of its elements
* 
* Dennis Ritchie said "C is a strongly typed, weakly checked language". The same applies to C++ templates,
* except that the checking of template argument requirements (concepts) is actually done, but it is done 
* too late in the compilation process and at an unhelpfully low level of abstraction.
* 
* 
*/