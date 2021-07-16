/**
 * A char is just a small integer, so char s may be freely used in arithmetic expressions. This permits 
 * considerable flexibility in certain kinds of character transformations. One is exemplified by this naive 
 * implementation of the function atoi, which converts a string of digits into its numeric equivalent.
 * 
 * Another example of char to int conversion is the function lower, which maps a single character to lower case 
 * for the ASCII character set. If the character is not an upper case letter, lower returns it unchanged.
 *
 * This works for ASCII because corresponding upper case and lower case letters are a fixed distance apart as 
 * numeric values and each alphabet is contiguous -- there is nothing but letters between A and Z. This latter 
 * observation is not true of the EBCDIC character set, however, so this code would convert more than just letters 
 * in EBCDIC. 
*/

/* atoi: convert s to integer */

int atoi(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}