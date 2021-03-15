/**
* Last we talked about the difference between continuous and non-continuous image access. Now the question is,
* how can we deal with the non-continuous images?
*
* In short, with such images, we need to skip the addition of (row-1)*column*n_channels offset, and directly
* start with the n_channels*(column - 1) offset. Now, if we're accessing the image through a loop, we can simply
* do what openCV advises us to at:
*
* https://docs.opencv.org/2.4/doc/tutorials/core/how_to_scan_images/how_to_scan_images.html#howtoscanimagesopencv
*
* Simply put, in a double for loop, we determine the number of rows
*/