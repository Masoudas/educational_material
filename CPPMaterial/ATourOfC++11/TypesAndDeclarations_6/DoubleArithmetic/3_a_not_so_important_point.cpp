/** A not so important issue this one:
* The standard says: "Due to maximal munch, hexadecimal integer literals ending in e and E, when followed by the 
* operators + or -, must be separated from the operator with whitespace or parentheses in the source."
* 
* The problem is that E is confused with the E of power!
*/

void defining_scientific_representation() {
	auto x = 0x224E10;	// This is fine
	auto y = (0x224E)+10;	// Error if no paranthesis
	

	auto w = 0.234E-1;

}