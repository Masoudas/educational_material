/**
 * As it happens in fact, getting environment variables is quite easy. We can use the getenv method which is part
 * of the stdlib header to get the environment variable we seek. The only argument required is the string name
 * of the variable.
 * 
 * Note that the \033[0;31m means color the output, with \033[ means start using a color, and then 0;36m or 0;30m
 * is a color. The whole thing apparently has to be terminated with a \033[0m. If we were to change the $TERM 
 * variable to a regular xterm, without color support, we would get a different output from the program:
 * $ TERM=xterm ./program  # (Or $ env TERM=xterm ./program)
 * $ TERM=screen-256color   ./program   (Regular terminal.)
 * 
 * Don't forget that the two functions printenv or env print all environment variables in Linux.
 */

#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
   /* Using getenv() to fetch env. variables */
   printf("Your username is %s\n", getenv("USER"));
   printf("Your home directory is %s\n", getenv("HOME"));
   printf("Your preferred editor is %s\n", getenv("EDITOR"));
   printf("Your shell is %s\n", getenv("SHELL"));
   
   /* Check if the current terminal support colors*/
   if ( strstr(getenv("TERM"), "256color")  )
   {
      /* Color the output with \033 + colorcode */
      printf("\033[0;31mYour \033[0;32mterminal "
         "\033[0;35msupport "
         "\033[0;36mcolors\033[0m\n");
   }
   else
   {
      printf("Your terminal doesn't support" 
         " colors\n");
   }

   return 0;
}