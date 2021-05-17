/**
* We also use the concept of a token_stream class, which returns tokens for us. A token maybe a number, a 
* string (denoting a name) or an operation. The idea is that we have a token_stream class that has a get 
* method, which returns the next token.
* 
* Given our definition of a token, we first define an enumration that's called Kind, which contains the
* kind of token. The token then would contain three fields, which are Kind, a double, and a string (for 
* names.)
*/