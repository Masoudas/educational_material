/**
* Unfortunately, C++ does not have specific language facilities for directly expressing concepts. However, handling 
* 'concepts' as a design notion only and presenting them informally as comments is not ideal. For starters, 
* compilers do not understand comments, so requirements expressed only as comments must be checked by the 
* programmer and cannot help the compiler provide good error messages. Experience shows that even though concepts 
* cannot be represented perfectly without direct language support, we can approximate them using code that performs 
* compile-time checks of template argument properties.
* 
* Naturally, a concept is a 'Compile Time Perdicate', that is, we think of a concept as a set of compile time 
* conditions (function) that check the template and return true if they're satisfied. Consequently, we implement a 
* concept as a constexpr function, and then se and static_assert statement to check for proper behavior of the
* function. The big guy also says "Here, I will use the term constraints check to refer to a call of a constexpr 
* predicate that checks a concept for a set of types and values. In contrast to proper concepts, a constraints 
* check does not deal with semantic issues; it simply checks assumptions about syntactic propertie"
*/