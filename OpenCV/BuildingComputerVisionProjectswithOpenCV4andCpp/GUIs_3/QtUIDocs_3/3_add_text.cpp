/**
 * Note: This function adds the text on the image, and not the window. Hence, we can actually for example add
 * an email adress or something to a video using this function.
 * 
 *      -   void cv::addText(const Mat& img, const String& text, Point org,	const QtFont& font)
 *      Draws a text on the image.
 *      The function addText draws text on the image img using a specific font font (see example cv::fontQt )
 *
 *          Parameters:
 *              *    img    :	8-bit 3-channel image where the text should be drawn.
 *              *    text	:   Text to write on an image.
 *              *    org	:   Point(x,y) where the text should start on an image.
 *              *    font	:   Font to use to draw a text.  	
 * 
 * 
 *      -   void cv::addText(const Mat& img, const String& text, Point org, const String& nameFont,
 *                           int pointSize = -1, Scalar color = Scalar::all(0), int weight = QT_FONT_NORMAL,
 *                  		 int style = QT_STYLE_NORMAL, int spacing = 0) 	
 *          Parameters:
 *              *   nameFont:	Name of the font. The name should match the name of a system font (such as Times*). 
 *                  If the font is not found, a default one is used.         
 *              *   pointSize:	Size of the font. If not specified, equal zero or negative, the point size of the 
 *                  font is set to a system-dependent default value. Generally, this is 12 points. 
 *              *   color:	Color of the font in BGRA where A = 255 is fully transparent. 
 *              *   spacing	Spacing between characters. It can be negative or positive. 
 * 
 * We also have the enumerations QtFontStyles and QtFontWeights.
 */