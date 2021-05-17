/**
* So imagine that the lines can be read from a file, or from the command line. We use istream class to take
* care of both situtations. Moreover, we consider both cases where our token_stream class may or may not own
* the istream class.
* 
* The implementation of each of Kind, Token and Token_Stream is given down below.
* 
* Note that Kind is implemented as a char enum, allowing a handy comparison with input chars when necessary.
* Moreover, note that as we discussed, a Token consists of three fields, a string, a double and a Kind. When
* the Token is an operation (per se) we don't convert to string, or when it's number, we don't convert to 
* number as well.
* 
* Finally notice how we read the input stream, which is indeed the most interesting part of this application.
* The standard-library function isalpha() is used to avoid listing every character as a separate case label. 
* Operator >> applied to a string (in this case, string_value) reads until it hits white space. Consequently, 
* a user must terminate a name by a space before an operator using the name as an operand. This is less than 
* ideal. But we discuss this later again. Notice how we did the same thing for number. These little tweaks
* are amazing. Moreover, as soon as we hit a digit, we read a double, which just as easily takes care of
* numbers for us. Note that we could have either peeked the next value in the stream, or as we've done in
* the following example, we just put what we've read back in the stream.
* 
* Finally, note that before reading the next char, we skip whitespaces. Skipping white spaces can be done
* using isspace, which we use to determine whether a given char is white space.
*/

#include <iostream>

using namespace std;

enum class Kind : char {
	name, number, end,
	plus = '+', minus = '-', mul = '*', div = '/', print = ';', assign = '=', lp = '(', rp = ')'
};

struct Token {
	Kind kind;
	string string_value;
	double number_value;
};

struct Token_Stream {
	istream* ip;
	bool owns = false;
	Token ct{ Kind::end };

	Token_Stream(istream& _ip) : ip{&_ip} {}

	Token_Stream(istream* _ip) : ip{ ip } {}

	Token get() { 
		char ch = 0;
		*ip >> ch;	// Get next char from the stream.

		do { // skip whitespace except ’\n’
			if (!ip->get(ch)) return ct={Kind::end};
		} while (ch != '\n' && isspace(ch));

		switch (ch) {
		case 0:
			return Token{ Kind::end };
		case ';':
			return Token{ Kind::end };
		case '+':
			return Token{ Kind::plus };
		case '-':
			return Token{ Kind::minus };
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8' : case '9':
		case '.':
			ip->putback(ch);	// Put back the char we just read.
			*ip >> ct.number_value; // read the number into ct! Holy molly! We just read numbers directly!
			ct.kind=Kind::number;
			return ct;
		default:
			if (isalpha(ch)) {	// We're passed an alpha value or expression
				ip->putback(ch); // put the first character back into the input stream
				*ip>>ct.string_value; // read the string into ct
				ct.kind=Kind::name;
				return ct;
			} 

		//	error("bad token"); Some kind of error function.
			return ct = { Kind::print };
		}


	}; // read and return next token
	
	Token& current() { ct; }; // most recently read token

	void set_input(istream& s) { close(); ip = &s; owns=false; }
	void set_input(istream* p) { close(); ip = p; owns = true; } 

private:
	void close() { if (owns) delete ip; }

};