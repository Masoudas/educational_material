/**
 * Note that this discussion is revolves around how we store any sort of data in opencv. The discussion regarding
 * how we store images comes next.
 * 
 * In many applications, such as calibration or machine learning, when we finish performing a number of 
 * calculations, we need to save these results to retrieve them in subsequent operations. OpenCV provides an 
 * XML/YAML persistence layer to this end.
 * 
 * The structure for this end is called FileStorage, which we shall discuss next.
 */
