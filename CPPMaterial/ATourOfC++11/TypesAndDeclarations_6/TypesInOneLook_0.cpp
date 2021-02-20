/**
 * char is at least 8 bits. May be signed or unsigned.
 * 
 * int is always signed. No guarantee on size.
 * short is always at least 16. No guarantee on sign.
 * long is at least 32 bits. No guarantee on sign.
 * 
 * We always have 
 * sizeof(char) <= sizeof(short)<= sizeof(int) <= sizeof(long int) <= sizeof(long long int)
 * 1<=sizeof(bool)<=sizeof(long)
 * sizeof(float)<=sizeof(double)<=sizeof(long double)
 * sizeof(N) = sizeof (unsigned N) = sizeof(signed N).
 * 
 */