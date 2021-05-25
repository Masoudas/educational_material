/**
* Implicit conversion sequence consists of the following, in this order:
*	(1) zero or one standard conversion sequence;
*	(2) zero or one user-defined conversion;
*	(3) zero or one standard conversion sequence.
* 
* When considering the argument to a constructor or to a user-defined conversion function, only a standard 
* conversion sequence is allowed (otherwise user-defined conversions could be effectively chained). When 
* converting from one built-in type to another built-in type, only a standard conversion sequence is allowed.
* 
* A standard conversion sequence consists of the following, in this order: 
*	(1) zero or one conversion from the following set: lvalue-to-rvalue conversion, array-to-pointer 
*		conversion, and function-to-pointer conversion;
*	(2) zero or one numeric promotion or numeric conversion;
*	(3) zero or one function pointer conversion;
*	(4) zero or one qualification conversion.
* 
* A user-defined conversion consists of zero or one non-explicit single-argument converting constructor or 
* non-explicit conversion function call
* 
* An expression e is said to be implicitly convertible to T2 if and only if T2 can be copy-initialized from e, 
* that is the declaration T2 t = e; is well-formed (can be compiled), for some invented temporary t. Note 
* that this is different from direct initialization (T2 t(e)), where explicit constructors and conversion 
* functions would additionally be considered
*/

