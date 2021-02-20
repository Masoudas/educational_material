/**
 * As we already know, for built-in types a function uses the copy semantics. The reason why is 
 * that if that value is auto (is on stack), it will be destroyed when the function call ends, hence the need
 * for creating a copy.
 * 
 * 
 * We can chain the return if two methods both return void.
 */
void void_retuner() {};
void double_void_retuner(){ return void_retuner();}

/**
 * The return type can be written after the function argument list, in which case we should use auto.
 * 
 * auto function(int a) -> int;
 * 
 * The returned value is checked against the return type of the function, and all necessary implicit and
 * explicit casts are performed.
 * double f(){return 1};    // One is cast from int to double.
 */

/**
 * Using a return statement is one of the five ways a function execution terminates.
 * 1- Executing return statement
 * 2- Falling off the end of the function body, which happens in the case of void functions, or main 
 * 3- Throwing an uncaught exception
 * 4- Throwing an exception when it's not caught locally and the function has noexcept
 * 5- Calling system functions that don't return such as exit().
 * 
 * A function that does not return normally can be marked with [[noreturn]]
 */
