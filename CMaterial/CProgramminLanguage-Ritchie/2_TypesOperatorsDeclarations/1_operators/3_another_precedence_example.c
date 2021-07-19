/**
 * Consider the following example:
 
int n, array[SIZE], getint(int *);
for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++);

 * Notice that we used a bad structure and declared a function together with variables. In any case, we know that
 * the operator precdence here is <, != and then &&. Hence, naturally, the above expression needs no paranthesis.
 * 
 * Notice the difference between assignment (=) and !=. Indeed, if we had a = instead of a !=, then we would have
 * required a paranthesis.
 * 
 * Below, as a bonus, we give the implementation of get int. I also propose an actually much simpler myself below.
 */

#include <ctype.h>
#include <stdio.h>

int getch();
void ungetch(int);


/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;
	while (isspace(c = getch()));	/* skip white space. Indeed a very nice loop! */

	// If not a number, or EOF, or + or -, return.
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		// ungetch(c); /* unget seems deprecated */
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();

	for (*pn = 0; isdigit(c); c = getch())
	 	*pn = 10 * *pn + (c - '0');

	*pn *= sign;

	//if (c != EOF)
	//	ungetch(c); Akh!
	
	return c;
}

#include <string.h>
#include <stdlib.h>
// For all intents and purposes, I'm happy with this function! Yes, the user might put 1+1, but to hell with that
// user! Even the check against 0 is not necessary, because atoi returns for 0123 123, which is fine by me!
// We could just as easily define a getfloat function.
int getint_mine(char* pn){
	char* c = (char*)malloc(10);

	size_t len = 10;
	int size = getline(&c, &len, stdin);	// Read this number and compare the size.
	if (strspn(c, "+-0123456789") != (size-1) || c[0] == '0')
		return -1;

	strncpy(pn, c, strlen(c));
	int val = atoi(c);
	free(c);
	return val;
}
