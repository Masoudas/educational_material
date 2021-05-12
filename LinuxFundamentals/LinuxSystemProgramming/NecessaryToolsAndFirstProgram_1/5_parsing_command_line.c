/**
 * In this example, we write a program that will parse and compare command line options. In particular, we expand
 * the program in 3 to have a -m or -a option. 
 * 
 * The function that we use for comparison of strings is the famous strcmp function, which is in the string
 * header. Note that strcmp does not require any length, given that strings terminate in '\0'. However, the
 * placement of the option makes it difficult for us to parse directly ourselves.
 * 
 * Instead, what we do is to use Linux fascilities. unistd is the standard unix input/output header. In 
 * particular, the getopt function ia the function that determins whether we have options from an specified
 * list, and returns -1 otherwise (as char.) The return value is in fact one of the options, and we use
 * it together with a switch case to parse the command line. Notice that only the option letter is parsed 
 * with this method. The getopt parses all argv to see if our option is present or not.
 * 
 * Note that if we write '1 2 3 -m' instead of '-m 1 2 3', we get a zero everytime. This is because the 
 * program uses atoi with m, which returns 0 for case it's not an integer.
 * 
 */

#define _XOPEN_SOURCE 500 // We better include it!
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printhelp(char progname[]);
int main(int argc, char *argv[])
{
    int i, opt, sum;

    /* Simple sanity check */
    if (argc == 1 || argc == 2)
    {
        printhelp(argv[0]);
        return 1;
    }

    /* Parse command-line options */
    if ((opt = getopt(argc, argv, "smh")) != -1)
    {
        switch (opt)
        {
           case 's': /* sum the integers */
               sum = 0;
               for (i=2; i<argc; i++)
                   sum = sum + atoi(argv[i]);
               break;
           case 'm': /* multiply the integers */
               sum = 1;
               for (i=2; i<argc; i++)
                   sum = sum * atoi(argv[i]);
               break;
           case 'h': /* -h for help */
               printhelp(argv[0]);
               return 0;
           default: /* in case of invalid options*/
               printhelp(argv[0]);
               return 1;
        }
        printf("Total: %i\n", sum);
        return 0;
    }
    return -1;
}

void printhelp(char progname[])
{
    printf("%s [-s] [-m] integer ...\n", progname);
    printf("-s sums all the integers\n"
        "-m multiplies all the integers\n"
        "This program takes any number of integer "
        "values and either add or multiply them.\n"
        "For example: %s -m 5 5 5\n", progname);
} 