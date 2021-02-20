/** This is me:
* Often, we want to distinguish what happens to an argument when passed as lvalue ref, rvalue ref, or pointer.
* 
* In short, lvalues and rvalues are distinguished by template argument deduction. An lvalue of type X is 
* deduced as X&, whereas an rvalue is deduced as X!!!!! Hence, std::forward deduces the type of an rvalue template
* as T, and not T&&. This fine though. For example, if we're passing an int, the actual value of the int is
* forwareded, which is exactly what we look for.
* 
* Note that this differs from the binding of values to non-template argument rvalue references.
* 
* In what follows, we shall discuss what the big guy says on this front.
*/
