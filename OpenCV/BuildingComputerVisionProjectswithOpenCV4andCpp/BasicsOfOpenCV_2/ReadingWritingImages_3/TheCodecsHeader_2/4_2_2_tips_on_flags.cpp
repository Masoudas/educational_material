/**
 * Here's a systematic approach to the flags I think is proper:
 * 
 *  -   Grayscale images:
 *      -   Read as is:         Use ANYDEPTH or UNCHANGED (keeps unsigned and signed)
 *      -   Convert to 8bit:    Use GRAYSCALE
 *      -   No conversion to color image upon reading.
 * 
 *  -   Color images:
 *      -   Read as is:                       Use UNCHANGED (always converts to BGR)
 *      -   Convert to 8bit BGR:              Use COLOR
 *      -   Convert to grayscale, keep depth: Use ANYDEPTH
 *      -   Convert to 8bit grayscale:        Use GRAYSCALE
 *  
 */        