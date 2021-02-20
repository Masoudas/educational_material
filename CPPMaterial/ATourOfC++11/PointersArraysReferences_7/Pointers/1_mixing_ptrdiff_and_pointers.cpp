/** This is me:
* As we already know, adding an integer to a pointer yields a pointer (to a new memory location). This is a 
* technique we normally use to increment pointers. Note that in reality, the expressions ptr + 5 are not addition
* of pointer to int, but rather addition of pointer to ptrdiff_t! In other words, 5 here is first implictly 
* converted to ptrdiff_t. This is the reason why when we write an iterator for example, we don't ask for an int
* for operators such as operator-, operator+, etc. But we rather ask for a differnce_type, which is in many
* cases just a ptrdiff_t (See chapter 33, section WritingAWrapperIterator.)
*/

void adding_int_to_pointer() {
	int i = 10;
	int* p = &i;
	p++;	// Next address of integer. This in my windows machine 4 memory addresses greater than p.

	char x = 10;
	p += x;		// Ok. Promoted to int probably and then added to p.

	float w = 10;
	//p += w; Error. Can't add float to pointer.

}