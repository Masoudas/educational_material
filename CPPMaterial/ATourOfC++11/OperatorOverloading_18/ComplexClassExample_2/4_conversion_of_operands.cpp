/**
* Going back to what we discussed in 2, if we have more conversions between types, then we need to overload the 
* addition functions for each type (int, double, etc), which can become tedious and thus error prone.
* 
* What we can do instead is to define the proper type conversions using the constructors. 
* 
* This of course is not a universal law, and for example if there's a simpler algorithm that can be applied for the ops,
* we better actually override the operations.
*
* An object constructed by explicit or implicit use of a constructor in an expression is automatic and will be destroyed at 
* the first opportunity
* 
* Note that no implicit user-defined conversions are applied to the left-hand side of a . (or a ->). This is the case even 
* when the . is implicit. 
* 
* Thus, we can approximate the notion that an operator requires an lvalue as its left-hand operand by making that operator a 
* member. However, that is only an approximation because it is possible to access a temporary with a modifying operation, such 
* as operator+=(): 

complex x {4,5} 
complex z {sqr t(x)+={1,2}}; // like tmp=sqrt(x), tmp+={1,2}
 
* If we don’t want implicit conversions, we can use explicit to suppress them.
*/