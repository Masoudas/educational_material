/**
 * Notice the difference between a string literal and an array of chars. While the latter has no zero terminating
 * char at the end (automatically) the former always does.
 * 
 * Moreover, if we consider the following:

char amessage[] = "now is the time";  an array
char *pmessage = "now is the time";  a pointer

 * we should recall that amessage is an array, and even though the length of amessage and pmessage is the same,
 * The pointer version even though not declared constant IS constant. Therefore, if we try to modify it, we get
 * undefined behavior.
 * 
 * Once again, recall how the following work:
 
 *p++ = val; // Push into the stack
  val = *--p;	// Pop front of stack. That is, decrement p, then read its value.

 * 
 */
#include <stdio.h>

int main(){
	char* p = "Mama, these Frenchs are in my face right now!";

	p[2] = 'x';	// Error! Modifying const array.

}



