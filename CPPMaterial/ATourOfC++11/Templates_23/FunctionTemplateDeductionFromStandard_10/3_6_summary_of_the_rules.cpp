/**
* If I want to summarize these rules all at once, before deduction begins:
*	(1)	For A (i.e, for passed values), unless we have reference, writing const does not contribute to deduction. 
*		Pointer to arrays collapse to element, and for passed functions they become pointer to functions.
* 
*   (2) For P (i.e, the type deduced from the template parameter):
*		- cv qualifier is omitted
*		- referenced type is replaced by the type, except that:
*			-	For forward references (cv-unqualified rvalue reference), if lvalue is passed, P is replaced by 
*				lvalue reference.
*
* The standard continues: "After these transformations, the deduction processes as described below (cf. section 
* "Deduction from a type") and attempts to find such template arguments that would make the deduced A (that is, 
* P after adjustments listed above and the substitution of the deduced template parameters) identical to the 
* transformed A, that is A after the adjustments listed above."
* 
*/

//Why remove_reference is not deduced?