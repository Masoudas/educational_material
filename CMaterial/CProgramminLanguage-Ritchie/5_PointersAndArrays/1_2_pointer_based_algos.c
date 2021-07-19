// Find the char position, and return -1 otherwise.
#include <string.h>
int findchar(char* s, char c){
	if (!c){
		return strlen(s);
	}

	char* p_s = s;
	while( *p_s && *p_s != c){ // If p_s is non-empty and is not the char
		++p_s; // This increment cannot be inside the condition, otherwise, p_s may exceed string length!
	};	

	return !*p_s ? -1 : p_s - s;
}

// A copy of string copy with pointers.
void strcp(char* s, char* d){
	while( (*s++ = *d++) != '\0');	// Even though s and are right associated and are applied first, they work
									// as post increment.
	// An even simpler version is as follows:
	while ( (*s++ = *d++));	// '\0' is just zero!
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp(char *s, char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	
	return *s - *t;
}
