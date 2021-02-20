/**
* As we already know, a c-style string is a pointer to an array of chars. The reason for this is that
* we want the buffer to consecutive in memory.
* 
* As we already know, for T arr[], arr is a pointer array of pointers of type T. Moreover,
* it decays to a pointer to type T for each arr + i.
* 
* Now, imagine we have an array of c-style strings, or const char* arr[]. What is the content of each
* arr + i? It is a pointer to const char* of course. Note that we talked about content. Hence, 
* arr + i in and of itself is a pointer to const pointer to char, or const char**.
* 
* Naturally, the address of arr is a constant pointer to an array of pointer to chars!
*/
void array_of_cstyle_strings() {
	const char* arr[] = { "1", "2", "3" };	// arr is a 1D array of pointer to const char*.

	const char** a1 = arr;
	const char** a2 = arr + 1;

	const char* (*ptr)[3] = &arr;
}