/**
 * As we said, we must think of a 1D array as a 1D array of pointers to type.
 * Hence, when we say T a[size], the transition to T* p = a is natural.
 * 
 * However, this transition is not natural for higher order arrays. In other words,
 * there's no direct conversion from a multi-dim array to pointer to pointers.
 * 
 * So for example, suppose we want to convert a 2D char array to a pointer to pointer of char. We need to
 * manually convert it to an array of pointers (by getting the pointer to the first element
 * of each row), and then assign that to a pointer to pointer, as shown below:
 */
void defining_pointer_to_pointer(){
    char a[2][3];

    char *ptr[2]; // array of two pointers to char; Note that direct initialization by saying {&a[0][0], &a[1][0]}
                // is not a good idea, because as we said in _3_2, the order may change.
    
    for (int i = 0; i < 2; i++)
    {
        ptr[i] = &a[i][0];
    }
    
    char** pptr = ptr;  // And this is what we seek.
} 