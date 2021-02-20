/**
* The default meaning of &&, ||, and , (comma) involves sequencing: the first operand is evaluated 
* before the second (and for && and || the second operand is not always evaluated). This special rule 
* does not hold for user-defined versions of &&, ||, and , (comma); instead these operators are treated 
* exactly like other binary operators.
* 
* (Me: As Jason Turner of CPP weekly points out, these operators should never be overloaded! The fact that
* these are not short-circuited could be one crucial reason for that. See Ep. 157 of CPPWeekly.)
*/