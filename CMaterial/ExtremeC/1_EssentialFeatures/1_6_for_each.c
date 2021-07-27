/**
 * Before introducing foreach in C++, boost was the library that provided for each with the BOOST_FOREACH command. In
 * the following example, we shall provide a for each loop for 'n' number of arguments.
 * 
 * This pattern is exactly like what we used in meta-programming in C++ to create type functions. Note that in the 
 * following if we pass less than equal 3 params, we'd be fine. On the other hand, if pass more than three, they'd
 * be ignored.
 * 
 * Question: Can we define a recursion in the macro, and say for example:
 
#define LOOP(X, ...) printf("%s", #X); LOOP(__VA_ARGS__)

 * Nope unfortunatenly. I think because this is a not a object in memory, we can't use the definition of the macro
 * inside of it. How about the following:

#define LOOP1(X, ...) printf("%s", #X), LOOP(_VA_ARGS__)
#define LOOP(X, ...) printf("%s", #X); LOOP1(__VA_ARGS__)

 * Again not, because LOOP is still an undefined symbol here. So we can see that apparently, we have no choice but the
 * one suggested below. That is to expand one argument, then two arguments, and then three.
 * 
 * This approach (and not using a while loop for example) is called loop unrolling. This leads to code bloat of course,
 * however it is still useful in many situations, especially as it increases performance.
 * 
 * Loop unrolling as such is useful in embedded environments.
 */

#include <stdio.h>
#define LOOP_3(X, ...) \
  printf("%s\n", #X);
#define LOOP_2(X, ...) \
  printf("%s\n", #X); \
  LOOP_3(__VA_ARGS__)
#define LOOP_1(X, ...) \
  printf("%s\n", #X); \
  LOOP_2(__VA_ARGS__)
#define LOOP(...) \
  LOOP_1(__VA_ARGS__)

int main(int argc, char** argv) {
  LOOP(copy paste cut)
  LOOP(copy, paste, cut)
  LOOP(copy, paste, cut, select)
  return 0;
}




