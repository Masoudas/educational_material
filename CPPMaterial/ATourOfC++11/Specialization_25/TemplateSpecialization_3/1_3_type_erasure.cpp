/**
* Concluding the remarks on the void* technique discussed prior, some compilers are getting smart enough 
* to perform this particular optimization without help from the programmer, but the technique is generally 
* applicable and useful. 
* 
* Variants of the technique of using a single run-time representation for values of a number of types and 
* relying on the (static) type system to ensure that they are used only according to their declared type 
* has been called type erasure. In the context of C++, it was first documented in the original template 
* paper [Stroustrup,1988].
*/