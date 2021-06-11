/**
 * The purpose of this program is to get an option -c from the user. If this option is present, we simply skip
 * any errors we might encounter when reading (that is, facing non digit chars.) Otherwise, we return an error.
 * 
 * Note that we passed two arguments to the printHelp() function. The first argument is a FILE pointer. We use 
 * this to pass stderr or stdout to the function. Stdout and stderr are streams, which can be reached via their 
 * FILE pointer. This way, we can choose if the help message should be printed to stdout (in case the user asked 
 * for the help) or to stderr (in case there was an error).
 * 
 * We could have written the program to do all the steps for us, such as filter out the values from the text file, 
 * do the conversions, and then write the result to a new file. But that's an anti-pattern in Linux and Unix. 
 * Instead, we want to write small tools that do one thing only—and do it well. That way, the program can be used 
 * on other files with a different structure, or for a completely different purpose. We could even grab the data 
 * straight from a device or modem if we wanted to and pipe it into our program. The tools for extracting the 
 * correct fields from the file (or device) have already been created; there's no need to reinvent the wheel.
 */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define _XOPEN_SOURCE 500 // We better define it

void printHelp();

int main(int argc, char* argv[]){
   int cont = 0;
   
   int op = 0;
   switch (op = getopt(argc, argv, "hc"))
   {
       case 'h':
        printHelp(stdout, argv[0]);
        return EXIT_SUCCESS;
        
      case 'c':
       cont = 1;
       break;
   
      default:
       break;
   }

    char line[10] = {'\0'};

    while(fgets(line, sizeof line, stdin) != NULL){
        if (strspn(line, "0123456789.-\n") == strlen(line))
        {
            fprintf(stdout, "%f\n", atof(line) * 1.60934 );
        } else 
        {
            fprintf(stderr, "The given string is not a floating point number\n");
            if (cont == 0){
                return EXIT_FAILURE;
            }
        }
    }

    return 0;
}

void printHelp(FILE *stream, char progname[])
{
   fprintf(stream, "%s [-c] [-h]\n", progname);
   fprintf(stream, " -c continues even though a non" 
      "-numeric value was detected in the input\n"
      " -h print help\n");
} 