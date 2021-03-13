/**
* CV::Mat is the basic structure (class) for representing an image. In the case of a grayscale image, we use a
* single m*n matrix. In the case of a colored image, we use three such matrices.
* 
* We can use Mat for any algebraic operation that involves matrices, so not just images.
* 
* Mat has been implemented in such a way that it's not a templated type, which is quite interesting, and challenging
* too during implementation.
* 
* Historically, the OpenCV website says "OpenCV has been around since 2001. In those days the library was built 
* around a C interface and to store the image in the memory they used a C structure called IplImage. This is the one 
* you'll see in most of the older tutorials and educational materials. The problem with this is that it brings to 
* the table all the minuses of the C language. The biggest issue is the manual memory management. It builds on the 
* assumption that the user is responsible for taking care of memory allocation and deallocation. While this is not 
* a problem with smaller programs, once your code base grows it will be more of a struggle to handle all this rather 
* than focusing on solving your development goal.
*
* Luckily C++ came around and introduced the concept of classes making easier for the user through automatic memory 
* management (more or less). The good news is that C++ is fully compatible with C so no compatibility issues can 
* arise from making the change. Therefore, OpenCV 2.0 introduced a new C++ interface which offered a new way of 
* doing things which means you do not need to fiddle with memory management, making your code concise (less to write, 
* to achieve more). The main downside of the C++ interface is that many embedded development systems at the moment 
* support only C. Therefore, unless you are targeting embedded platforms, there's no point to using the old methods 
* (unless you're a masochist programmer and you're asking for trouble)."
*
* Mat is basically a class with two data parts: the matrix header (containing information such as the size of the 
* matrix, the method used for storing, at which address is the matrix stored, and so on) and a pointer to the matrix 
* containing the pixel values (taking any dimensionality depending on the method chosen for storing) . The matrix 
* header size is constant, however the size of the matrix itself may vary from image to image and usually is larger 
* by orders of magnitude. 
*/