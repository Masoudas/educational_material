/**
* A namespace is a mechanism for expressing logical grouping. That is, if some declarations logically belong together according to some criteria, they can be put in 
* a common namespace to express that fact. Note that main cannot be in a namespace, because main should be in the
* global namespace.
* We see that no implementation is provided in these namespaces. Implementation clutters the namespace, thus
* presenting difficulty in finding the interface of the module.

namespace Parser {
	double expr(bool);
	double prim(bool get) { }
	double term(bool get) { }
	double expr(bool get) { }
}

namespace Lexer {
enum class Kind : char { };
class Token {  };
class Token_stream { };
Token_stream ts;
}

namespace Table {
map<string,double> table;
}

namespace Driver {
void calculate() { }
}

namespace Error {
int no_of_errors;
double error(const string& s) { }
}

int main() { }
*/