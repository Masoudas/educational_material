/**
* 
* The question that may arise here is that how do we get the pointer to underlying image matrix? The answer is 
* that we use the template ptr<>(i) function, where 'i' is the row number. There's however a point. Note that 
* the template here is type, not pointer (hence uchar NOT uchar*).
* 
* Note: There are two ways in which the image matrix is stored:
*   1- If the system allows it, the underlying matrix is stored as a continuous 1D array. Hence, there would 
*	   exist only one pointer to the entire image structure. We can use it to access every element.
*   2- The matrix is stored as a series of pointers to rows. Therefore, we need to get the pointer to every row,
*      and then work from there.
* To find out which version is used, we use the isContinuous() function of the matrix. True means that we are
* dealing with a 1D array.
* 
* Note that the ptr function returns pointer to the row we requested. Hence, it does not depend on how the image
* is tiled in memory.
* 
* Note finally that the ptr template has to be determined by us, the user. If for example we're dealing with an
* unsigned 8 bit grayscale image, we get a uchar* pointer. Else, we get a double or float pointer, or uint pointer.
*/

