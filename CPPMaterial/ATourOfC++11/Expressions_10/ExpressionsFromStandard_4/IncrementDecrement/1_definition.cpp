/**
* Me: Note that essentially, ++x is equivalent to x+=1 or x = x + 1. Hence, if for a char I say ++c, then first it's 
* promoted to int for math operation, then the operation is performed, and finally we have an implicit cast from int to
* char!
* 
* Increment/decrement operators increment or decrement the value of the object. Below we show both the arithmetic and
* member as well as class stand-alone versions of the operator:
* 
*	-	pre-increment		++a;			T& T::operator++();				T& T::operator++(T&);
*	-	pre-decrement		--a;			T& T::operator--();				T& T::operator--(T&);		
*	-	post-increment		a++;			T T::operator++(int);			T T::operator++(T&, int);
*	-	post-decrement		a--;			T T::operator--(int);			T T::operator--(T&, int);
* 
* Note: Prefix versions of the built-in operators return references and postfix versions return values, and typical 
* user-defined overloads follow the pattern so that the user-defined operators can be used in the same manner as the 
* built-ins. However, in a user-defined operator overload, any type can be used as return type (including void).
* 
* Note: The int parameter is a dummy parameter used to differentiate between prefix and postfix versions of the operators.
* when the user-defined postfix operator is called, the value passed in that parameter is always zero, although it may be 
* changed by calling the operator using function call notation (e.g., a.operator++(2) or operator++(a, 2)).
* 
* Note: Using an lvalue of volatile-qualified non-class type as operand of built-in version of these operators is 
* deprecated.
*/

void reminder_on_increment_ops() {
	int x = 10;
	int &y  = ++x;	// Pre-increment, and return a reference. Both x and y refer to x, and have the same value!
	int w = ++x;	// Note: A copy takes place here.

	//int& z = x++; Error! Assigning rvalue to lvalue.
}