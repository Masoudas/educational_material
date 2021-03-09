/**
* It's important to understand how the matrix is stored inside the class, to access image elements by pointer. This
* is always faster calling functions.
*
* So here's the layout structure: Every pixel location contains the number of channels. We traverse every column,
* and then go to the next row.In this schema, it's obvious that if we wanted to access row 'r', column 'c', and
* channel 'i', we have to compute the following formula:
*
* Value = r * (c - 1 ) * i + c * i + i
*
* Note that it does appear that the formula in the book is wrong, as can be checked in this page on the OpenCV
* website (https://docs.opencv.org/2.4/doc/tutorials/core/how_to_scan_images/how_to_scan_images.html#howtoscanimagesopencv).
*
*
*/

/** Recall that in C++, we have [dim3][row][column] **/
void reminder_on_cpp_matrices() {
    int Multi[2][3][2] =
    {
      {
        {14, 11},
        {13, 10},
        { 9,  6}
      },
      {
        { 8,  7},
        { 1,  5},
        { 4,  2}
      }
    };
};
