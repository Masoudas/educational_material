/**
 * Here, we link against the math library. Note that linkeage during compilation is done using '-lm' 
 * (in /usr/lib/x86_64-linux-gnu/libm.so) against the math library (why is this library here?).
 * 
 * As a reminder, note that libc.so contains the standard functions, and we always link against it, whereas 
 * libm.so is not part of the standard, which is why we have to specifically link against it.
 * 
 * Note that the documentation for the libraries can be found at manpages at 'man libc' for example.
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    int years = 15; /* The number of years you will 
                     * keep the money in the bank 
                     * account */
    int savings = 99000; /* The inital amount */
    float interest = 1.5; /* The interest in % */
    printf(
	"The total savings after %d years is %.2f\n", years, 
 	savings * pow(1+(interest/100), years));
    return 0;
}