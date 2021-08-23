/**
 * Array of chars has a unique property that by default, it can be considered as an array of pointers, unlike
 * for example an array of ints, whose column length must be known.
 */

void array_of_chars(){
	char *arr[] = {"Here", "There", "And everywhere"};	// Notice that the second element need not be declared.

	char *arr_[15] = {"Here", "There", "And everywhere"};	// Notice that this one has static dimensions, and has
															// empty chars left, as opposed to the previous one.
}