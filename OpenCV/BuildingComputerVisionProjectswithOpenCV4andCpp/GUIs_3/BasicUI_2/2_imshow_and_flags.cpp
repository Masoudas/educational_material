/**
 * Here's the documentation of imshow from the OpenCV website, which states that every image is shown as a 255
 * pixel range:
 * 
 *      -   void cv::imshow(const String& winname, InputArray mat)
 *      Displays an image in the specified window.
 *  
 *      The function imshow displays an image in the specified window. If the window was created with the 
 *      cv::WINDOW_AUTOSIZE flag, the image is shown with its original size, however it is still limited by the 
 *      screen resolution. Otherwise, the image is scaled to fit the window. The function may scale the image, 
 *      depending on its depth:
 *      
 *          *   If the image is 8-bit unsigned, it is displayed as is.    
 *          *   If the image is 16-bit unsigned or 32-bit integer, the pixels are divided by 256. That is, the 
 *              value range [0,255*256] is mapped to [0,255].    
 *          *   If the image is 32-bit or 64-bit floating-point, the pixel values are multiplied by 255. That is,
 *              the value range [0,1] is mapped to [0,255].
 * 
 *      If window was created with OpenGL support, cv::imshow also support ogl::Buffer , ogl::Texture2D and 
 *      cuda::GpuMat as input. 
 * 
 *      If the window was not created before this function, it is assumed creating a window with 
 *      cv::WINDOW_AUTOSIZE.
 *
 *      If you need to show an image that is bigger than the screen resolution, you will need to call 
 *      namedWindow("", WINDOW_NORMAL) before the imshow. 
 * 
 *      Note: This function should be followed by cv::waitKey function which displays the image for specified 
 *      milliseconds. Otherwise, it won't display the image. For example, waitKey(0) will display the window 
 *      infinitely until any keypress (it is suitable for image display). waitKey(25) will display a frame for
 *      25 ms, after which display will be automatically closed. (If you put it in a loop to read videos, it 
 *      will display the video frame-by-frame) 	
 * 
 * The following flags for the basic GUI (non-Qt version) are of interest:
 *      -   WINDOW_NORMAL: This flag allows the user to resize the window
 *      -   WINDOW_AUTOSIZE: If this flag is set, the window size is automatically adjusted to fit the display 
 *          image and it is not possible to resize the window
 * 
 */