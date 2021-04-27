/** This is me:
* Question: Can we override the new operator in the global namespace for int for example? That is, define:

void* operator new(int);

* The answer is no. This is because the first parameter of new has to be size_t.
*/
