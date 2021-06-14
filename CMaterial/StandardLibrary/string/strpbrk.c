/**
 *  -   char* strpbrk( const char* dest, const char* breakset );
 * 
 * Scans the null-terminated byte string pointed to by dest for any character from the null-terminated byte string 
 * pointed to by breakset, and returns a pointer to that character.
 * 
 * The behavior is undefined if either dest or breakset is not a pointer to a null-terminated byte string.
 * 
 */

#include <stdio.h>
#include <string.h>

void search_char(void)
{
    const char* str = "hello world, friend of mine!";
    const char* sep = " ,!";
 
    unsigned int cnt = 0;
    do {
       str = strpbrk(str, sep); // find separator
       if(str) str += strspn(str, sep); // skip separator
       ++cnt; // increment word count
    } while(str && *str);   // If str is null or points to terminatio char.
 
    printf("There are %u words\n", cnt);
}

int main(){
    search_char();
}

 
