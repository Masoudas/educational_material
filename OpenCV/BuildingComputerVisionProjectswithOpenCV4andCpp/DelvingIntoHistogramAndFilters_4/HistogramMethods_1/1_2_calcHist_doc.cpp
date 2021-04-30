/**
 * As such, we normally put the output of hist into another image. In that scheme, every pixel (i=0, 1, ...)
 * corresponds to one bin. Hence, for non-uniform bins, we need to remember our bins.
 * 
 * Notice that we can supply an array of images to this function to calculate the histogram among all of them.
 * A single Mat matrix mat thus better be supplied to the function using &mat.
 *  
 * The calcHist has three overloads, two of which are the more important ones:
 * 
 *  -   void cv::calcHist(const Mat* images, int nimages, const int* channels, InputArray mask, 
 *      OutputArray hist, int dims, const int* histSize, const float** ranges, bool uniform = true,
 *		bool accumulate = false)
 *      *   images:	    Source arrays. They all should have the same depth, CV_8U, CV_16U or CV_32F , and 
 *                      the same size. Each of them can have an arbitrary number of channels.
 *      *   nimages:	Number of source images.
 *      *   channels:	List of the dims channels used to compute the histogram. The first array channels are 
 *                      numerated from 0 to images[0].channels()-1 , the second array channels are counted 
 *                      from images[0].channels() to images[0].channels() + images[1].channels()-1, and so on.
 *      *   mask:   	Optional mask. If the matrix is not empty, it must be an 8-bit array of the same 
 *                      size as images[i] . The non-zero mask elements mark the array elements counted in the 
 *                      histogram.
 *      *   hist:   	Output histogram, which is a dense or sparse dims-dimensional array.
 *      *   dims:   	Histogram dimensionality that must be positive and not greater than CV_MAX_DIMS 
 *                      (equal to 32 in the current OpenCV version).
 *      *   histSize:	Array of histogram sizes in each dimension (me: Number of bins in each size)
 *      *   ranges: 	Array of the dims arrays of the histogram bin boundaries in each dimension. When the 
 *                      histogram is uniform ( uniform =true), then for each dimension i it is enough to 
 *                      specify the lower (inclusive) boundary L0 of the 0-th histogram bin and the upper 
 *                      (exclusive) boundary UhistSize[i]−1 for the last histogram bin histSize[i]-1 . That 
 *                      is, in case of a uniform histogram each of ranges[i] is an array of 2 elements. When 
 *                      the histogram is not uniform ( uniform=false ), then each of ranges[i] contains 
 *                      histSize[i]+1 elements: L0,U0=L1,U1=L2,...,UhistSize[i]−2=LhistSize[i]−1,
 *                      UhistSize[i]−1 . The array elements, that are not between L0 and UhistSize[i]−1 , are 
 *                      not counted in the histogram.
 *      *   uniform:    Flag indicating whether the histogram is uniform or not (see above).
 *      *   accumulate:	Accumulation flag. If it is set, the histogram is not cleared in the beginning when 
 *                      it is allocated. This feature enables you to compute a single histogram from several 
 *                      sets of arrays, or to update the histogram in time. 
 *                      (me: What it does is that it does not clear the content of the Mat matrix. It just 
 *                      adds to it. There's no static variable inside the function involved :D) 	
 *
 *  -   void cv::calcHist(InputArrayOfArrays images, const std::vector< int > & channels,
 *		InputArray mask, OutputArray hist, const std::vector<int>& histSize, 
 *      const std::vector<float>& ranges, bool accumulate=false) 	
 * 
 * Note: As we can see, the histSize parameter is an int array. It does not make sense (my friend) to 
 * calculate histogram for a float image.
 * 
 * Reminder: float** is a pointer to point of float. Hence, an array that contains float pointers would be 
 * implicitly converted to an array of floats. Such an array as we know by know is not equivalent to a 2D array
 * of floats. Hence, to make such an array, create separate arrays of floats, then create the final array of
 * floats:
 
 float f1[3] = {1, 2, 3};   // Array of floats. Implicit to float*
 float f2[3] = {4, 5, 6};   

 float* arr[2] = {f1, f2};  // Array of float pointers. Implicitly converts to pointer to float*, or float**.
 float* arr2 = &f1; // Second option for a single pointer to pointer.
 */