/**
 * Me: Often, when we want to get the result of an algorithm in OpenCV, we need to supply an instance of a Mat.
 * The create matrix ensures that the proper matrix dimension is allocated for the result. Hence, often, we don't
 * need to worry about supplying the proper image dimension for the result of an operation. We just need to 
 * supply a default constructed matrix.
 * 
 * Allocates new array data if needed. 
 * This is one of the key Mat methods. Most new-style OpenCV functions and methods that produce arrays call this 
 * method for each output array. The method uses the following algorithm:
 * 
 *  -   If the current array shape and the type match the new ones, return immediately. Otherwise, dereference 
 *      the previous data by calling Mat::release.
 *  -   Initialize the new header.    
 *  -   Allocate the new data of total()*elemSize() bytes.    
 *  -   Allocate the new, associated with the data, reference counter and set it to 1.  
 * 
 * Such a scheme makes the memory management robust and efficient at the same time and helps avoid extra typing 
 * for you. This means that usually there is no need to explicitly allocate output arrays. That is, instead of 
 * writing: 
 * 
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * Mat color; 
 * ...
 * Mat gray(color.rows, color.cols, color.depth());
 * cvtColor(color, gray, COLOR_BGR2GRAY);
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * 
 * you can simply write: 
 * 
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * Mat color;
 * ...
 * Mat gray;
 * cvtColor(color, gray, COLOR_BGR2GRAY);
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * 
 * Me: Note that the overloads of create are essentially the same as constructors of Mat, hence, we won't dive
 * in any further.
 */