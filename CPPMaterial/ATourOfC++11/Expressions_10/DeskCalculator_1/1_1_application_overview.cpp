/**
* The intent here is to write a desk calculator application. As we may recall, a calculator maybe fed an 
* expression like the following:
* 
* 2 * 1 + 1 / 3 + 4
*
* We shall call the 2 * 1 part term, and each of 1 or 2 as primary. An expression consists of a list of
* terms in this manner. A primary could be numbers, ops, and (), or a name (like pi for example.) Note
* that we assume that an expression can end in either a semi-colon or a new line. Note also that an assignment
* can take place as well, therefore allowing a user to assign a name.
* 
* The big guy, draws the following grammer for the program then:

program:
	end // end is end-of-input
	expr_list end
expr_list:
	expression print // print is newline or semicolon
	expression print expr_list
expression:
	expression + term
	expression - term
	term
term:
	term / primary
	term * primary
	primary
primary:
	number // number is a floating-point literal
	name // name is an identifier
	name = expression
	- primar y
	( expression )
*
*/

