/**
 * A constant expression is an expression that involves only constants. Such expressions may be evaluated at 
 * during compilation rather than run-time, and accordingly may be used in any place that a constant can occur, as 
 * in:
 
#define MAXLINE 1000
char line[MAXLINE+1];

 * or:

#define LEAP 1 // in leap years //
int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];

 *
 */