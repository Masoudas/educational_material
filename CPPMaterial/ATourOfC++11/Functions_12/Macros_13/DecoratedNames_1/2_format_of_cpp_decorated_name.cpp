/**
* In C++, a decorated name is formed as follows:
* 1-	The function name.
* 2-	The class that the function is a member of, if it is a member function. 
*	This may include the class that encloses the class that contains the function, and so on. 
* 3-	The namespace the function belongs to, if it is part of a namespace.
* 4-	The types of the function parameters.
* 5-	The calling convention.
* 6-	The return type of the function.
* 
* The function and class names are encoded in the decorated name. 
* The rest of the decorated name is a code that has internal meaning only for the compiler and the linker.
* 
* Here are two examples:
* int a(char){int i=3;return i;}	------		?a@@YAHD@Z
* void __stdcall b::c(float){};		------		?c@b@@AAGXM@Z
* 
* 
*/