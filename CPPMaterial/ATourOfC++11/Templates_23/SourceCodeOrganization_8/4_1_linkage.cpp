/**
* The rules for linkage of templates are the rules for linkage of the generated classes and functions. This implies 
* that if the layout of a class template or the definition of an inline function template changes, all code that 
* uses that class or function must be recompiled.
* 
* (Me: Note we say the definition of an INLINE function. This is because inline function is copy pasted where we
* use it. If the function weren't inline, then obviously we wouldn't need recompilation, because we only work with
* the interface. In this case, only linkage and binary generation need to change.)
* 
* For templates defined in header files and included "everywhere," this can imply a lot of recompilation because 
* templates tend to include a lot of information in header files, more than non-template code using .cpp files.  
* In particular, if dynamically linked libraries are used, care has to be taken that all uses of a template are 
* consistently defined.
* 
* 
*/