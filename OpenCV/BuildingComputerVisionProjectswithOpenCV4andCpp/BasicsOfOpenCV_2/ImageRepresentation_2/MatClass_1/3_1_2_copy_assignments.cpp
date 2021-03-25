/**
 * At this point, it would be best to consider the copy ctors and assignment ops of OpenCV. It's important to 
 * understand the 'Range' class prior to understanding those constructors however:
 * 
 * Range class:
 * Template class specifying a continuous subsequence (slice) of a sequence.
 * The class is used to specify a row or a column span in a matrix ( Mat ) and for many other purposes. 
 * Range{start_inclusive, end_exclusive} specifies '[start_inclusive, end_exclusive)'.
 * 
 * The method 'Range::all()' is a static method and returns [Int_min, Int_max), allowing the entire range of possible
 * values.
 * 
 * Note from me: We're starting to observe more and more that in OpenCV, exceeding a defined range does not cause 
 * exception. For example, if we wanted to copy the entire rows of an image, we don't neccessarily have to provide
 * the exact [0, row) range, but rather Range::all() suffices.
 * 
 * Note from me: Once again, never forget that the concept of columns points to the number of horizontal pixels, and
 * not how many elements are needed to represent them. For example, a 1*1 three channel image still has exactly one 
 * column, but is represented with a 1*3 matrix.
 * 
 */ 
 
 /* 
 * And now, we have the following list of constructors for Mat: Recall that none of these operations create a new
 * copy of the matrix so long as we don't call the clone method. We can think of these cloning operations as ones
 * involving defining new matrix headers for all or parts of the matrix (and not cloning the data)
 *  
 * The copy constructors are:
 *     -      Mat(const Mat &m)
 *          This would be the normal copy ctor of image.
 *   
 *      -     Mat(const Mat &m, const Range &rowRange, const Range &colRange=Range::all())
 *          Copy the given row and column range. This would copy all the channels. Note that rows start from zero.       
 * 
 *      -     Mat(const Mat &m, const Rect &roi)
 *          Copy the given ROI of the image. 
 * 
 *      -     Mat(const Mat &m, const Range *ranges)
 *          Copy the given matrix over the given range by providing an array of ranges. It differs from the above
 *          row-column range only in the way it accepts arguments.
 * 
 *      -     Mat(const Mat &m, const std::vector< Range > &ranges)
 *          Same as above, but only accepts ranges through a vector.
 * 
 * The copy assignment operators are:
 *      -   Mat & 	operator=(const Mat &m)
 *      	assignment operators Assigned, right-hand-side matrix. Matrix assignment is an O(1) operation. This means 
 *          that no data is copied but the data is shared and the reference counter, if any, is incremented. Before 
 *          assigning new data, the old data is de-referenced via Mat::release 
 *
 *      -   Mat & 	operator=(const MatExpr &expr)
 *          Assigned matrix expression object. As opposite to the first form of the assignment operation, the second 
 *          form can reuse already allocated matrix if it has the right size and type to fit the matrix expression 
 *          result. It is automatically handled by the real function that the matrix expressions is expanded to. 
 *          For example, C=A+B is expanded to add(A, B, C), and add takes care of automatic C reallocation. 
 *          
 *      -   Mat & 	operator=(const Scalar &s)
 *          Sets all or some of the array elements to the specified value. 
 * 
 * Apart from these, we have the following functional operators that are dedicated to essentially the same task.
 * Notice that all of these return a new matrix instance (as expected):
 * 
 *      -   Mat 	operator()(Range rowRange, Range colRange) const
 *          Extracts a rectangular submatrix. The operators make a new header for the specified sub-array of *this. 
 *          They are the most generalized forms of Mat::row, Mat::col, Mat::rowRange, and Mat::colRange . For 
 *          example, A(Range(0, 10), Range::all()) is equivalent to A.rowRange(0, 10). Similarly to all of the above, 
 *          the operators are O(1) operations, that is, no matrix data is copied. 
 *
 *      -   Mat 	operator()(const Rect &roi) const
 *          ...         
 * 
 *      -   Mat 	operator()(const Range *ranges) const
 *          ...         
 * 
 *      -   Mat 	operator()(const std::vector< Range > &ranges) const
 *          ...
 * 
 * There's also these functions, which are just another expressions of the functional operators. Notice that all of 
 * these return a new matrix instance (as expected):
 * 
 *      -   Mat 	rowRange(int startrow, int endrow) const
 *	        Creates a matrix header for the specified row span. The method makes a new header for the specified 
 *          column span of the matrix.
 *
 *      -   Mat 	rowRange(const Range &r) const
 * 
 *      -   Mat     row(int row) const
 *          Returns a new header for the given row.
 * 
 *      -   Mat 	colRange(int startcol, int endcol) const
 *          Same as row, but for column
 *      	
 *      -   Mat 	colRange(const Range &r) const
 */