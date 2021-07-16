/**
 * The relational operators are ">, >=, <, <=". They all have the same precedence. Just below them in precedence 
 * are the equality operators "== !="
 * 
 * Relational operators have lower precedence than arithmetic operators, so an expression like i (lim-1) , as 
 * would be expected.
 * 
 * More interesting are the logical operators && and || . Expressions connected by && or || are evaluated left to 
 * right, and evaluation stops as soon as the truth or falsehood of the result is known. Most C programs rely on 
 * these properties.
 * 
 * The precedence of && is higher than that of || , and both are lower than relational and equality operators, so 
 * expressions like:
 
i < lim-1 && (c=getchar()) != ’\n’ && c != EOF
 
 * require no paranthesis. (why is c=getchar() in paranthesis? the reason is that the precedence of != is greater 
 * than =.
 * 
 * Recall that unary operators have the higher precedence. A common use of ! is in constructions like:
 
if (!valid)

 * rather than:

if (valid == 0)
 
 * It’s hard to generalize about which form is better. Constructions like !valid read nicely (‘‘if not valid’’), 
 * but more complicated ones can be hard to understand.
 
 */
#include <stdio.h>

int main(int argc, char* argv[]){
	int lim = 20;
	char s[20];
	for ( int i = 0, c = '\0'; i < lim-1 && (c=getchar()) != '\n' && c != EOF; i++ ){
		s[i] = c;
	}
	printf("%s\n", s);	
}