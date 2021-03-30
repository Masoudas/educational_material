/**
* Face recognition is different from face detection, in that we try to identify the person from the image. Therefore,
* it's not just a matter of detecting faces, but rather matching the features on those faces.
* 
* If we want to build a practical biometric system that can recognize the person in front of the camera, we first 
* need to run a face detector to identify the location of the face, and then run a separate face recognizer to 
* identify who the person is. There is an OpenCV module called face that deals with face recognition.
* 
* As we discussed earlier, computer vision tries to model algorithms based on how humans perceive visual data. So, 
* it would be helpful to find salient regions and objects in the images that can help with different applications 
* such as object recognition, object detection and tracking, and so on. There is a module called saliency that's 
* designed for this purpose. It provides algorithms that can detect salient regions in static images and videos.
* 
*/