/**
 * Macro functions have essentially the same syntax as a normal function, except for lack of return type, argument type,
 * and brackets. Macro functions are replaced as string arguments in the preprocessor. For example, below if we use 
 * ADD(2,1), then 2+1 is replaced in our code. So macro functions are merely string replacements. In other words, we 
 * could have similarly substituted ADD(x,y), as shown below:
 * 
 * In a macro function, all instances of input arguments are replaced with whatever is given as argument, and are used
 * for preprocssor. Macro functions do not perfom any computation.
 * 
 * Macros only exist before the compilation phase. This means that the compiler, theoretically, doesn't know anything 
 * about the macros. This is a very important point to remember if you are going to use macros instead of functions. 
 * The compiler knows everything about a function because it is part of the C grammar and it is parsed and being kept 
 * in the parse tree. But a macro is just a C preprocessor directive only known to the preprocessor itself.
 */

#define ADD(a,b) a + b;

int main(int argc, char** argv) {
  int x = 2;
  int y = 3;
  int z = ADD(x, y);
  return 0;
}