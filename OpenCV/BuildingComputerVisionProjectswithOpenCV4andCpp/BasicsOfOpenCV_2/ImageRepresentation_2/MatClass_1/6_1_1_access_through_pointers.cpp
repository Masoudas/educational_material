/**
 * Access through a pointer is probably the fastest way of accessing the image matrix. The methods for getting a
 * pointer to the underlying data are very simple. In fact, we can use the following templated methods (which are
 * in essence like those of cv::Mat::at) to directly access the underlying structure. Again, note that like the
 * at methods, we have methods to get the pointer to a row, row column, three dims, or higher that 3 dims (and
 * we once again must not forget that a 2D image with multiple channels has only 2 dim:)
 *
 *      -   Tp_* cv::Mat::ptr<Tp_>(int	i0 = 0)
 *      -   Tp_* cv::Mat::ptr<Tp_>(int row, int column)
 *      -   Tp_* cv::Mat::ptr<Tp_>(int i0, int i1, int i2)
 *      -   Tp_* cv::Mat::ptr<Tp_>(const int* idx)
 * 
 * Note it's generally possible to start from the first pixel of the image, and then move forward from there, using
 * the pointer of the first element, assuming the Mat structure has allocated exactly one row vector to the image. 
 * However, we need to ensure that this in fact is the case, using the isContinuous method, which we discuss next.
 */