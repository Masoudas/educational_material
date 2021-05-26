/**
 * To define shapes of particular type for morphological filters, we use the getStructuringElement function.
 * The sort of shapes we get are determined by the MurphShapes enumeration:
 * 
 * enum MurphShapes{
 *      MORPH_RECT      :   a rectangular structuring element,
 *      MORPH_CROSS     :   a cross-shaped structuring element,
 *      MORPH_ELLIPSE   :   an elliptic structuring element, that is, a filled ellipse inscribed into the 
 *                          rectangle Rect(0, 0, esize.width, 0.esize.height)        
 * }
 * 
 *  -   Mat cv::getStructuringElement(int shape, Size ksize, Point anchor = Point(-1,-1)) 		
 */
