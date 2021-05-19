/**
 * This one is dedicated to my old buddy Pedram. PSNR stands for peak signal to noise ratio. It's a quality 
 * measure of the image. The function is documented as follows:
 * 
 *      -   double cv::PSNR(InputArray src1, InputArray src2) 	 
 *      Computes the Peak Signal-to-Noise Ratio (PSNR) image quality metric.
 *      This function calculates the Peak Signal-to-Noise Ratio (PSNR) image quality metric in decibels(dB), 
 *      between two input arrays src1 and src2. Arrays MUST have depth CV_8U.
 *      
 *      The PSNR is calculated as follows:
 *                                      PSNR=10log10(R^2/MSE)
 *      where R is the maximum integer value of depth CV_8U (255) and MSE is the mean squared error between 
 *      the two arrays. (Me: Hence, it's the measure of maximum signal value over mean noise.)
 */