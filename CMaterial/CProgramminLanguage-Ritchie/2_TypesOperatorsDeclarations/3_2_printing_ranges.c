/**
 * Here's a program to print the possible ranges of values for every basic type in C, using the limits header.
 */

#include <limits.h>
#include <float.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	signed char sc_min = SCHAR_MIN;
	signed char sc_max = SCHAR_MAX;

	// min of us is 0!
	unsigned char uc_max = UCHAR_MAX;
	
	// ...
	float f_min = FLT_MIN;
	float f_max = FLT_MAX;
 
	printf("signed char [%i, %i], unsigned char [0, %u],\nfloat [%12f, %12f]\n", 
		sc_min, sc_max, uc_max, f_min, f_max);
	
	return 0;
}