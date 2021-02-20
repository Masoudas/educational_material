/**
* The reason why we need modularity is clear. Imagine a class name exists in both our global namespace
* and a libraries'. Attempting to include that library results in a name clash. 
* 
* (Now me: The name clash if coming from headers can be ignored, like we discussed in 2. However, as soon as
* we arrive at body redefinition of classes and methods, the compiler fails).
*/