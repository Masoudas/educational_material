/**
 * Consider the following function. What we do is we directly copy the content of argv[1] into a string. Now,
 * note that we don't exactly know the size of argv[1], and we've allocated a compile-time array of size 10.
 * This in more serious situations is a vulnerability, and should be avoided, because the memory that's not
 * going to be filled can be exploited by an attacker, like we should in the previous example.
 * 
 * It would be better to use strlen here, together with allocation of memory on the heap:
 
 char* ptr = (char*)malloc(strlen(argv[1]));
 strncp(ptr, argv[1], strlen(argv[1]));

 */

int main(int argc, char** argv) {
  char str[10];
  strcpy(str, argv[1]);
  printf("Hello %s!\n", str);
}