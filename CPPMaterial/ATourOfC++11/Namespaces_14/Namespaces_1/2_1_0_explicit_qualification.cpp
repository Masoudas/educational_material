/**
* A member can be declared within a namespace definition and defined later using the 
* namespacename :: member-name notation.
* 
* Members of a namespace must be introduced using this notation:
"""""""""""""""""""""""""""""""""""""""""""""""
namespace name{ // members here}
""""""""""""""""""""""""""""""""""""""""""""""""
* Note the lack of semicolon at the end (unlike class). 
* 
* We cannot declare a NEW member for a namespace outside a namespace definition using the qualifier syntax.
* Why? Because if we did so, the compiler would not be able to determine whether we made an error, or we want
* to declare a new function.
* 
* A namespace is a scope. The usual scope rules hold for namespaces. (Another famous scope: enum!)
*
*/

namespace Parser {
	double expr(bool); // declaration
	double term(bool);
	double prim(bool);
}

double val = Parser::expr(false); // use
double Parser::expr(bool b) // definition
{
	// ...
	return 0.0;
}

//void Parser::logical(bool); // error : no logical() in Parser
//double Parser::trem(bool); // error : no trem() in Parser (misspelling)
//double Parser::prim(int); // error : Parser ::prim() takes a bool argument (wrong type)
//void Parser::m1(){};	// Does not depend on whether we fully declare the method.