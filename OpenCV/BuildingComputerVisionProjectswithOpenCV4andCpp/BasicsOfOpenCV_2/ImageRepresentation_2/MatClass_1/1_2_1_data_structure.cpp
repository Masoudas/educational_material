/**
 * The documentation on the opencv website for the Mat class states that:
 * 
 * The class Mat represents an n-dimensional dense numerical single-channel or multi-channel array. It can be used 
 * to store real or complex-valued vectors and matrices, grayscale or color images, voxel volumes, vector fields, 
 * point clouds, tensors, histograms (though, very high-dimensional histograms may be better stored in a 
 * SparseMat ).
 * 
 * The data layout of the array 'cv::Mat M' is defined by the array M.step[], so that the address of element 
 * (i0,...,iM.dims−1), where 0 ≤ ik < M.size[k], is computed as:
 * 
 *          addr(M_i0,...,M_idims−1) = M.data + M.step[0]∗i0 + M.step[1]∗i1 + ... + M.step[M.dims−1]∗iM.dims−1 
 * 
 * (Me: In Layman's term, the step vector holds how many elements should be skipped for each dimension. For dim0,
 * step[0], for dim1, step[1], etc. dim0 points to row here, naturalich. Also notice that M.data is the pointer
 * to the data structure. The supposition is that data is a 1D array.)
 * 
 * In the particular case of a 2D image, one can write 'addr(i,j) = M.data + M.step[0]∗i + M.step[1]∗j'
 * Note that M.step[i] >= M.step[i+1] (in fact, M.step[i] >= M.step[i+1]*M.size[i+1] ). This means that 2-dimensional 
 * matrices are stored row-by-row, 3-dimensional matrices are stored plane-by-plane, and so on. M.step[M.dims-1] is 
 * minimal and always equal to the element size M.elemSize().
 * 
 * Example from me: If we have a 1 * 2 and three channel matrix, then step[0] = 2 * 3, and step[1] = 3, and finally
 * step[2] = 1. The fact that a 3 dimensional marix is stored plane by plane implies that for each pixel, we traverse
 * all plains, and then go to the next pixel, meaning we go through the channels of first element of first row, then
 * second element of first row, etc.
 * 
 * Me: Note that the concept of depth is associated with how many bits are allocated to representation of each
 * individual element in the matrix. The allowed depth are 8, 16, 32 and 64 bits. 
 * 
 * 
 */