/**
* Object detection refers to detecting the location of an object in a given image. This process is not concerned 
* with the type of object. If you design a chair detector, it will not tell you whether the chair in a given image 
* is red with a high back, or blue with a low back. It will just tell you the location of the chair.
* 
* Detecting the location of objects is a critical step in many computer vision systems.
* 
* Object detection used to be a computationally-intensive task because of the number of calculations required to 
* perform the detection at various scales. To solve this, Paul Viola and Michael Jones came up with a great 
* algorithm in their seminal 2001 paper, which you can read at the following link: 
* https://www.cs.cmu.edu/~efros/courses/LBMV07/Papers/viola-cvpr-01.pdf. They provided a fast way to design an 
* object detector for any object.
* 
* OpenCV has modules called objdetect and xobjdetect that provide the framework to design an object detector. You 
* can use it to develop detectors for random items such as sunglasses, boots, and so on.
*/