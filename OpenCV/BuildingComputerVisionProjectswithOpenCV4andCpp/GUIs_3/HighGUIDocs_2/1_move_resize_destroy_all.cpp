/**
 * Most functions of the basic OpenCV GUI we're already aware of. There's another ones as well:
 * 
 *      -   void cv::moveWindow(const String& winname, int x, int y)
 *      Moves the window to the specified (x,y) position. (Me: Allowing us not to open windows on top of one
 *      another.)
 * 
 *      -   void cv::resizeWindow(const String& winname, int width, int height)
 *      Resizes the window to the specified size. 
 *      Note: 
 *          *   The specified window size is for the image area. Toolbars are not counted.    
 *          *   Only windows created without cv::WINDOW_AUTOSIZE flag can be resized.
 * 
 *      -   void destroyWindow(const std::string&)
 *      Destroys the given named window.
 * 
 *      -   void cv::destroyAllWindows() 	
 *      Destroys all of the HighGUI windows. The function destroyAllWindows destroys all of the opened HighGUI 
 *      windows. 
 */