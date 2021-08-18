/**
 * It's possible to perform even more complex cmd parsing, assuming we're willing to use string cmp functions
 * for example. For example. we shown below, we can iterate over argv using argc, to determine how many arguments
 * are given, where argc indicates the total length of argv (including the program name.) As such, a condition
 * such as:
 
 while(--argc > 0){
	 ....
 }

 * is helpful, and we can avoid parsing the first argument, and start from the last argument.
 */
#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	while(--argc > 0){
		++argv;
		if ((*argv)[0] == '-' && (*argv)[1] == '-'){	// This is an option argument
			if (strstr(*argv, "my-option")){
				printf("Found --my-option\n");
			} 
		}
		//printf("%s\n", *argv);
		
	}
}