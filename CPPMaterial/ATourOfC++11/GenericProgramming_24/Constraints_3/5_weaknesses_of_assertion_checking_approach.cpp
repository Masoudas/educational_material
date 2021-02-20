/**
* There are a couple of issues associated with the above constraint checking method:
* 
* -	 Constraints checks are placed in definitions, but they really belong in declarations. That is, a concept is 
*	part of the interface to an abstraction, but a constraints check can be used only in its implementation (very
*	interesting insight.)
* -	 The checking of constraints occurs as part of the instantiation of the constraints-check template. Therefore, 
*	the checking may occur later than we would like. In particular, we would have preferred for a constraints check 
*	to be guaranteed to be done by the compiler at the point of the first call, but that is impossible without 
*	language changes. (Me: But I thought this is in fact done at first call.)
* -  We can forget to insert a constraints check (especially for a function template).
* -  The compiler does not check that a template implementation uses only the properties specified in its concepts. 
*	Thus, a template implementation may pass the constraints check, yet still fail to type check.
* -  We do not specify semantic properties in a way that a compiler can understand (e.g., we use comments).
*/