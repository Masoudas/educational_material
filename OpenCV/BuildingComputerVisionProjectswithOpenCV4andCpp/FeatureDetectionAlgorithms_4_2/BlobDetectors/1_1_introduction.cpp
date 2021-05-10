/**
 * By blob (a drop of a thick liquid or viscous substance) detection, we mean detecting the center of a blob
 * on an image.
 * 
 * We can use OpenCV feature detection functions to detect blobs
 * 
 * In particular, we use SimpleBlobDetector, which is located in the 'opencv2/features2d.hpp' header.
 * 
 * This class is used for extracting blobs from an image and implements a simple algorithm for extracting blobs 
 * from an image:
 *  -   Convert the source image to binary images by applying thresholding with several thresholds from 
 *      minThreshold (inclusive) to maxThreshold (exclusive) with distance thresholdStep between neighboring 
 *      thresholds.
 *  -   Extract connected components from every binary image by findContours and calculate their centers.
 *  -   Group centers from several binary images by their coordinates. Close centers form one group that 
 *      corresponds to one blob, which is controlled by the minDistBetweenBlobs parameter.
 *  -   From the groups, estimate final centers of blobs and their radiuses and return as locations and sizes 
 *      of keypoints.
 * 
 * This class performs several filtrations of returned blobs. You should set filterBy* to true/false to turn 
 * on/off corresponding filtration. Available filtrations:
 * 
 *  -   By color. This filter compares the intensity of a binary image at the center of a blob to blobColor. 
 *      If they differ, the blob is filtered out. Use blobColor = 0 to extract dark blobs and blobColor = 255 
 *      to extract light blobs.
 *  -   By area. Extracted blobs have an area between minArea (inclusive) and maxArea (exclusive).
 *  -   By circularity. Extracted blobs have circularity (4∗pi∗Area/(perimeter∗perimeter)) between 
 *      minCircularity (inclusive) and maxCircularity (exclusive).
 *  -   By ratio of the minimum inertia to maximum inertia. Extracted blobs have this ratio between 
 *      minInertiaRatio (inclusive) and maxInertiaRatio (exclusive).
 *  -   By convexity. Extracted blobs have convexity (area / area of blob convex hull) between minConvexity 
 *      (inclusive) and maxConvexity (exclusive).
 *
 * Note: Measure of circularity computes the area and permiter of the shape. A [erfect circle has then
 * 4pi*(pi*r^2) / (2*pi*r)^2 = 1. A square has 0.7. Note that in an image, we can only calculate the area and
 * the perimeter of a shape!
 * 
 * Note: Convexity is important because a circle that has 3 quarters may or maynot be considered a blob 
 * according to our need. A full circle has convexity of one.
 * 
 * Note: Interia is a measure of elongation. Hence, an ellipsoind can be considered a blob, or not.
 * 
 * See next how each filter must be used.
 */
