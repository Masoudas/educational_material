/**
 * There are several macros in the opencv library that determine the color space and resolution for us.
 * These have the apparent form "CV_nuCc", which stand for:
 *  - n:    The number of bits allocated to the image.
 *  - u:    S or U or F, which stand for signed, unsigned, and float.
 *  - C:    This capital letter is always there, and stands for channel
 *  - c:    The number of channels.
 * 
 * Exceptionally, we have the following types too. These types don't have a channel, which make them ideal for storing
 * data as matrices.:
 *   -	#define CV_8U    0
 *   -	#define CV_8S    1
 *   - 	#define CV_16U   2
 *   -  #define CV_16S   3
 *   -  #define CV_32S   4
 *   -  #define CV_32F   5
 *   -  #define CV_64F   6
 *   -  #define CV_16F   7
 * 
 * Question: Is there a difference between CV_8U and CV_8UC1? Nope. Note that in the macro definitions we have:
 * #define CV_8UC1   CV_MAKETYPE(CV_8U,1)   where 
 * #define CV_MAKETYPE(depth, cn)   (CV_MAT_DEPTH(depth) + (((cn)-1) << CV_CN_SHIFT))
 * 
 * and the second defintion leads to 0+((1-1) << 3) == 0, which is the same value as CV_8U.
 * 
 * Now, there are a couple of exceptional macros here that are interesting. The following are good for getting the 
 * pointer to the underlying image data, as we shall describe later:
 *    -   typedef uint32_t 	uint
 *    -   typedef signed char 	schar
 *    -   typedef unsigned char 	uchar
 *    -   typedef unsigned short 	ushort
 *    -   typedef int64_t 	int64
 *    -   typedef uint64_t 	uint64
 * 
 * Final thought: Note that we don't have all combinations of bit size and float or signed. For example, we
 * famously don't have 32 bit signed to unsigned image.
 */
