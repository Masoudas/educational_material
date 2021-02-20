/*
* When calling an object, function or data in C++, the compiler creates a name string for them to know which
* entity to call. It records calling conventions, types, function parameters and other information together
* with the name. This name decoration, also known as name mangling, 
* helps the linker find the correct functions and objects when linking an executable.
* 
* One reason why we need to compile every C++ dll or lib with the current compiler is that the
* convention for name mangling is different for each compiler.
* 
* Normally, we don't need to know about name conventions. However, sometimes when calling functions from
* other languages (such as C, assembly) we use these declaratives. Another case is 
* for example, to match overloaded C++ functions, members of namespaces, class constructors, 
* destructors and special member functions. We must specify the decorated name.
* 
* We can also view decorated names, using .obj file, or .asm file.
*/
