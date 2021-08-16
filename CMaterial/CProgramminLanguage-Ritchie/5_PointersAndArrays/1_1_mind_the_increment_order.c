/**
 * Consider the following:
 * ++*ip;
 * *++ip;
 * *ip++;
 * 
 * It's obvious that in the first example, start is applied before increment, incrementing the value of what's
 * pointed to rather than the pointer. In the second example, however, we increment the pointer, and then read what's
 * pointed to (meaning the next pointer value.)
 * 
 * The third example is a bit more complicated. Note that unary operators associate right to left. Therefore, we
 * first increment the pointer, then read its content. (Me: That being said, ++ has a higher priority than * as 
 * well.) So the change in ip would appear on the next line. We could think of it as ip++ returning ip in the
 * current line, and then * reading it.
 * 
 * Hence, if wanted to increment ip and not the pointer in the next line, the correct version would be to write 
 * (*ip)++.
 */

#include <stdio.h>

int main(){
	int i = 10;
	int* ip = &i;
	
	// Notice that post-increment applies the next time the variable is used!
	if ( (*ip)++ == 10 && *ip == 11 &&  ++*ip == 12 )
		printf("%i\n", i);	
}