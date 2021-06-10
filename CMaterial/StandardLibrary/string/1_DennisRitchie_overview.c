/**
 * There are two groups of functions in this header, ones starting with str and ones starting with mem.
 * Except for memmove, the behavior is undefined if copying takes place between overlapping objects. Comparison 
 * functions treat arguments as unsigned char arrays. 
 * 
 * Me: recall that both unsigned and signed chars map to the same chars, hence -128 points to the same as 128.
 * 
 * In the following table, variables s and t are of type char *; cs and ct are of type const char *; n is of type 
 * size_t; and c is an INT converted to CHAR. 
 * 
 *  -   char *strcpy(s,ct) copy string ct to string s, including ’\0’; return s.
 *  -   char *strncpy(s,ct,n) copy at most n characters of string ct to s; return s. Pad with ’\0’’s if ct 
 *      has fewer than n characters.
 *  -   char *strcat(s,ct) concatenate string ct to end of string s; return s.
 *  -   char *strncat(s,ct,n) concatenate at most n characters of string ct to string s, terminate s with
 *      ’\0’; return s.
 *  -   int strcmp(cs,ct) compare string cs to string ct, return <0 if cs<ct, 0 if cs==ct, or >0 if cs>ct.
 *  -   int strncmp(cs,ct,n) compare at most n characters of string cs to string ct; return <0 if cs<ct, 0
 *      if cs==ct, or >0 if cs>ct.
 *  -   char *strchr(cs,c) return pointer to first occurrence of c in cs or NULL if not present.
 *  -   char *strrchr(cs,c) return pointer to last occurrence of c in cs or NULL if not present.
 *  -   size_t strspn(cs,ct) return length of prefix of cs consisting of characters in ct.
 *  -   size_t strcspn(cs,ct) return length of prefix of cs consisting of characters not in ct.
 *  -   char *strpbrk(cs,ct) return pointer to first occurrence in string cs of any character string ct, or
 *      NULL if not present.
 *  -   char *strstr(cs,ct) return pointer to first occurrence of string ct in cs, or NULL if not present.
 *  -   size_t strlen(cs) return length of cs.
 *  -   char *strerror(n) return pointer to implementation-defined string corresponding to error
 * 
 *  -   char *strtok(s,ct) strtok searches s for tokens delimited by characters from ct; see below
 * A sequence of calls of strtok(s,ct) splits s into tokens, each delimited by a character from ct. The first call 
 * in a sequence has a non-NULL s, it finds the first token in s consisting of characters not in ct; it terminates 
 * that by overwriting the next character of s with ’\0’ and returns a pointer to the token. Each subsequent call, 
 * indicated by a NULL value of s, returns the next such token, searching from just past the end of the previous 
 * one. strtok returns NULL when no further token is found. The string ct may be different on each call. 
 */

#include <string.h>
#include <stdio.h>

