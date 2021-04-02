/**
* Several predicates are defined for use in the standard, such as is_integral, is_pointer, is_empty, is_polymorphic,
* is_move_assignable, etc.
* 
* Me: Recall that a polymorphic type is a type that has a virtual function.
* 
* Naturally, type predicates with more than one argument can also be useful. In particular, this is how we represent 
* relations between two types, such as is_same, is_base_of, and is_conver tible. These are also from the standard library.
*/