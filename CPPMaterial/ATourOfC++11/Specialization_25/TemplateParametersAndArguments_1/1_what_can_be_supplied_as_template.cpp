/**
* Essentially, three types of parameters can be supplied as templates:
* 1- Type parameters of "type"
* 2- Value parameters of built-in types such as ints, and pointers to functions.
* 3- Template parameters of "type template"
* 
* A template can take a fixed number of parameters or a variable number. The discussion of variadic templates is 
* postponed until chapter 28.
* 
* Note that it is common to use short names with initial uppercase letters as names of template type arguments, 
* for example, T, C, Cont, and Ptr. This is acceptable because such names tend to be conventional and restricted 
* to a relatively small scope. However, when using ALL_CAPS, there is always a chance of clashing with macros, so 
* don’t use names that are long enough to clash with likely macro names.
* 
* (Me: Note that the big guy insists that we can only supply types of built-in types. Consequently, we can't pass
* values of custom types, or their pointers for that matter. If we think about it, it does make sense. Because to
* pass values of custom types, we have to write something to the effect of 'template<S s>', but as we already know:
* - This is not allowed in C++ (at least in pre 20 area.)
* - What does this expression mean? Are we saying s is bounded to a template, or that we're passing a value!
* Therefore, especially if we consider the second statement, we see that passing a literal type as value in this
* way does not make sense. What we can do instead if we really want to do such a work is to use constexpr functions
* and create constexpr objects and pass them.)
*/