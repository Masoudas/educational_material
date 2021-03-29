/**
 * As opposed to the depth function, the elemSize method returns the size of elements in byte.
 *
 *      - size_t cv::Mat::elemSize() const
 *        Returns the matrix element size in bytes. 
 *        The method returns the matrix element size in bytes. For example, if the matrix type is CV_16SC3 , the 
 *        method returns 3*sizeof(short) or 6.
 *        (Hence, an element is the aggregate of all channels for a pixel.)
 *
 *      - size_t cv::Mat::elemSize1() const
 *        Returns the size of each matrix element channel in bytes. The method returns the matrix element channel 
 *        size in bytes, that is, it ignores the number of channels. For example, if the matrix type is CV_16SC3, 
 *        the method returns sizeof(short) or 2.
 *
 * Hence, these two methods return the number of bytes for a single channel of an image, or for all channels of an
 * image together.
 */