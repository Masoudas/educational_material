/**
* Let's say we want to extract the motion of an object in various frames of a video. Running the feature extraction
* algorithms can be expensive on each frame. Therefore, what we do is to extract the feature from the current frame,
* then follow it on the next frames. This is called optical flow.
* 
* Optical flow algorithms are heavily used in video-based applications in computer vision. The optflow module 
* contains all the algorithms required to perform optical flow. There is also a module called tracking that 
* contains more algorithms that can be used to track features.
*/