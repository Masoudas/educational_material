/**
 * Below is another example of an extreme macro usage. Notice that after preprocessing, we have:
 
...
... content of stdio.h …
...
int main(int argc, char** argv) {
  for (int counter = 1; counter <= 10; counter++) {
    printf("%d\n", counter);
  }
  return 0;
}

 * Notice that the content of #include is also replaced as part of preprocessor.  
 */

#include <stdio.h>
#define PRINT(a) \		
	 printf("%d\n", a);	// The backslash extends to the next line.
#define LOOP(v, s, e) for (int v = s; v <= e; v++) {
#define ENDLOOP }

int main(int argc, char** argv) {
  LOOP(counter, 1, 10)
    PRINT(counter)
  ENDLOOP
  return 0;
}