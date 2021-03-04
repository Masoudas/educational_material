/**
* Just as with a class, we can supply the template arguments for a function template. Note that just like a normal
* function argument, function templates should go to the end of the template argument list.
* 
* void f1(int x = 0, int y); // error : default argument not trailing
* void f2(int x = 0, int y = 1); // OK
* 
* template<typename T1 = int, typename T2> 
* class X1 { // error : default argument not trailing 
*	// ...
* };
* 
* template<typename T1 = int, typename T2 = double>
* class X2 { // OK
* // ...
* };
* 
*/