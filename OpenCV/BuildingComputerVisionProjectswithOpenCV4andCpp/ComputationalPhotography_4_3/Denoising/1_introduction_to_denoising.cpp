/**
 * We have seen many image smoothing techniques like Gaussian Blurring, Median Blurring etc and they were good 
 * to some extent in removing small quantities of noise. In those techniques, we took a small neighbourhood 
 * around a pixel and did some operations like gaussian weighted average, median of the values etc to replace 
 * the central element. In short, noise removal at a pixel was local to its neighbourhood.
 * 
 * There is a property of noise. Noise is generally considered to be a random variable with zero mean. Consider 
 * a noisy pixel, p=p0+n where p0 is the true value of pixel and n is the noise in that pixel. You can take 
 * large number of same pixels (say N) from different images and computes their average. Ideally, you should 
 * get p=p0 since mean of noise is zero.
 * 
 * You can verify it yourself by a simple setup. Hold a static camera to a certain location for a couple of 
 * seconds. This will give you plenty of frames, or a lot of images of the same scene. Then write a piece of 
 * code to find the average of all the frames in the video (This should be too simple for you now ). Compare 
 * the final result and first frame. You can see reduction in noise. Unfortunately this simple method is not 
 * robust to camera and scene motions. Also often there is only one noisy image available.
 * 
 * So idea is simple, we need a set of similar images to average out the noise. Consider a small window (say 
 * 5x5 window) in the image. Chance is large that the same patch may be somewhere else in the image. Sometimes 
 * in a small neighbourhood around it. What about using these similar patches together and find their average? 
 * For that particular window, that is fine. 
 * 
 * The blue patches in the image looks the similar. Green patches looks similar. So we take a pixel, take small 
 * window around it, search for similar windows in the image, average all the windows and replace the pixel 
 * with the result we got. This method is Non-Local Means Denoising. It takes more time compared to blurring 
 * techniques we saw earlier, but its result is very good. More details and online demo can be found at first 
 * link in additional resource
 * 
 * For color images, image is converted to CIELAB colorspace and then it separately denoises L and AB 
 * components.
 */