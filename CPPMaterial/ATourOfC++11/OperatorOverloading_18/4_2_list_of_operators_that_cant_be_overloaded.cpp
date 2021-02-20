/**
* The following operators can't be overloaded:
* ::	The scope operator
* .		The member access operator
* .*	Member through pointer access (see chapter 20)
* 
* These operators accept a name rather than a value (l or r value), therefore are different in nature.
* 
* The following named operators can't be overloaded, because they report fundamental facts about their type:
* sizeof()
* alignof()
* typeid()
* 
* Finally, the ternary operator can't be overloaded, for no fundamental reason.
*/