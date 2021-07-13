/**
 * In this example, we write a simple program to calculate the sum of two variables read from the command line.
 * Naturlich, we use the atof to convert the strings to double. This method can be found in the stdlib header.
 * 
 * Note that just like in C++ (!) the argv's first value is always the full program name, and the last one is 
 * always '\0', and we always have argc=1 arguments at least, which is the program name. '\0' is not counted
 * as argument, of course.
 * 
 * Notice that in the case of lacking arguments, we return a 1, indicating that the program terminated incorrectly,
 * We can check this as we may recall by running echo $? on the shell.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    if (argc == 1 || argc == 2){
        printf("Not enough arguments\n");
        return 1;
    }

    double sum = 0;
    for (int i = 1; i < argc; ++i){
        float arg1 = atof(argv[i]);
        sum += arg1;
    }

    printf("The sum is: %.3f\n", sum);
}