/**
* So, the big guy makes the simplification that we're not defining names, but we shall do it in what follows:
* 
* Starting from the expression, we define a function called 'expr'. This function uses the 'term' function to
* get a term from the expression. Once we have a term, we have two scenrios:
* 
*	-	First token is a name: In this case, we shall check in a separate loop if the next two tokens are
*		an '=' and a number. If this were the case, we'd set the new name in our dictionary of names.
*
* If this isn't the case, the token is a number then, which we shall set in a double. Now, in a for loop
*	-	If the next term is a +, we shall add to the current value.
*	-	If the next term is a -, we shall subtract from the current value.
*	-	If there's no next term, we shall just return.
* 
* Note that the big guy passes a boolean to all functions, indicating whether or not a next one (expression,
* term, primary) should be read or not, which we do as well here:

double expr(bool get){
	// Me: I added the if part
	if (ts.current().kind == Kind::name){
		// Add to dictionary
		return 0;
	}

	for (;;) { // "forever"
		switch (ts.current().kind) {
		case Kind::plus:
			left += term(true);
		break;
		case Kind::minus:
			left -= term(true);
			break;
		default:
			return left;
}
}
}

*/