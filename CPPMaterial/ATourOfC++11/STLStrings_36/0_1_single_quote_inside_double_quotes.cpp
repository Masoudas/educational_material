/**
* This occured to me while I was doing some bash scripting. 
* 
* What would happen if we use a single quote inside double quote strings? Well. Single quote is considered a
* char, right! So just like any other char, like a, b, c, it would be printed as is. Especially, recall 
* that I normally tend to contract is to say for example It's inside strings!
* 
* So as opposed to bash, single quote does nothing here.
*/

#include <stdio.h>

void single_quote_inside_double_quote() {
	const char* str = "Here's a single quote ' '";
}