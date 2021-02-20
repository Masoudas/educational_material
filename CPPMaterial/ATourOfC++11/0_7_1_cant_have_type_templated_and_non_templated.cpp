/**
* A type can't be both templated and non templated. Why? For one thing, the compiler can't check whether or not
* we've forgotten to put the templates, or we really don't need them. This is more because with types, the compiler
* is not responsible for deduction of type. This is also due to the fact that no resolution rules are defined for
* classes of course. I guess they didn't want to make matters compliaced!!
* 
* From another point of view, templates are part of the definition of the class (part of the type), which is not
* the case for functions.
*/

template<typename T>
struct S{};

// struct S {}; Error. Type can't be both templated and non-templated.

