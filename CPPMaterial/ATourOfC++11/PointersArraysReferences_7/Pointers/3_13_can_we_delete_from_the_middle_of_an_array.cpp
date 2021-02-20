/**
* Question: Imagine we've allocated a dynamic array. Now, can we delete an element from the middle, or end of it?
* Just to mess with people?
* 
* Note that when creating a dynamic array, we need to use delete[]. We can't use delete, or the run-time check 
* throws us an error. Hence, we can't!
* 
* Note however a point of danger here. We can delete the pointer with a delete, which implies just destroying the
* first element of an array, which is an error. This can be particualrly dangerous when working with smart pointers.
* In there, we must always use the unique_ptr<T[]> specialization for arrays. If we use, unique_ptr<T*>, it will use
* the delete operator, removing only the first memory!
* 
* There's a dirt workaround however for this. Getting a pointer from the middle of an array, and then try and
* delete it. Obviously, we get a run-time error if we did this. So, don't do it.
*/
#include <iostream>
void delete_array_with_proper_delete_operator() {
	int* arr = new int[5]{};

	//delete arr + 4; Error! Expression must have arithmetic, enum scope or pointer type.
	delete arr;

}