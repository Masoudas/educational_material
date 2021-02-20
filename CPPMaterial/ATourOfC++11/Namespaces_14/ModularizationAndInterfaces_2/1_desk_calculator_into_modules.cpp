/**
* The desk calculator in chapter 10 was a procedural program and had the following parts:
* 
* [1]	The parser, doing syntax analysis: expr(), term(), and prim()
* [2]	The lexer, composing tokens out of characters: Kind, Token, Token_stream, and ts
* [3]	The symbol table, holding (string,value) pairs: table
* [4]	The driver: main() and calculate()
* [5]	The error handler: error() and number_of_errors
* 
* Hence, driver->parser->lexer showing dependency, as well as driver->lexer->symbol table
* and parser->symbol table.
* 
* Now, we may want to extract an interface out of these, and then work with those. Here, an interface
* would only imply the declarations (and not a class interface).
* 
* We use this program in the following section.
*/