/**
* A point to note about the Parser namespace is that only expr is an actual interface function, and the other
* functions are implementation detail. So, we have two options here:
* 
* 1-	Either use two files and break the namespace as follows. That way, a user that only sees the header with
*	expr assumes that this is the only interface function. (Me: Intellisense had not been invented in 2011, and
*	thus, because namespaces are open, a user still sees all interface functions with intellisense).
* 
* 2-	Introduce an implementor namespace.
%%%%%%%%%% solution one:
namespace Parser { // user interface
	double expr(bool);
}

// In different header
namespace Parser { // implementer interface
	double prim(bool);
	double term(bool);
	double expr(bool);

	using namespace Lexer; // use all facilities offered by lexer
	using Error::error;
	using Table::table;
}

%%%%%%%% solution two:
namespace Parser { // user interface
double expr(bool);
}
namespace Parser_impl { // implementer interface
using namespace Parser;
double prim(bool);
double term(bool);
double expr(bool);
using namespace Lexer; // use all facilities offered by Lexer
using Error::error;
using Table::table;
}
*/
