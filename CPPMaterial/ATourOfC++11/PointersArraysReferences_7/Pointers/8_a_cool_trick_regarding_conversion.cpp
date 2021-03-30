/** This is from me:
 * I learned this trick from OpenCV, but one should be cautious about using such tricks. But in any case, such 
 * conversions seem to be the case, and what make C++ interesting.
 * 
 * Suppose we have an array of ints, and a structure of ints. We can easily convert the pointers of the former to
 * the latter, thus reading the elements of the array as an structure. We just need a simple cast of pointers.
 * Note that in this scheme, we're NOT creating a new object, we're JUST converting pointers.
 * The point is that the structure is designed in such a way that it contains the integers as three word from the
 * beginning. 
 * 
 * Also note that in such a way, the data of the structure does not have to be references, because the structure
 * pointer is pointing to the underlying data.
 * 
 */

struct point3D{
    int x,y,z;
};

void accessing_vector_of_3d_points(){
    int arr[] = {1, 1, 1, 2, 2, 2, 5, 6, 7};    // Imagine these as three points in the 3D space.

    point3D* p1 = (point3D*)(&arr[0]);

    int* p = static_cast<int*>(&arr[0]);
}