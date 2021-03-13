/**
* The website states: "The first thing you need to know about Mat is that you no longer need to manually allocate its
* memory and release it as soon as you do not need it. While doing this is still a possibility, most of the OpenCV 
* functions will allocate its output data automatically. As a nice bonus if you pass on an already existing Mat 
* object, which has already allocated the required space for the matrix, this will be reused. In other words we use 
* at all times only as much memory as we need to perform the task."
*
*
* It further goes on to state that "The idea is that each Mat object has its own header, however a matrix may be 
* shared between two Mat objects by having their matrix pointers point to the same address. Moreover, the copy 
* operators will only copy the headers and the pointer to the large matrix, not the data itself."
* 
* Essentially what this implies is that mat does not make copies of the underlying data, unless we explicitly ask
* it to do so.
*
* Example:

Mat A, C;                          // creates just the header parts
A = imread(argv[1], IMREAD_COLOR); // here we'll know the method used (allocate matrix)
Mat B(A);                                 // Use the copy constructor
C = A;                                    // Assignment operator

* In all of the above, all three matrices point to the same underlying data.
*/
