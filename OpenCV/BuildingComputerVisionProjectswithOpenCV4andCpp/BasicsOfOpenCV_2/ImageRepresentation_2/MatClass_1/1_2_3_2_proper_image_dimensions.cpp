/** This is from me:
 * Essentially, we must consider a normal 2D image separately from higher dimensional images. Moreover, Based on 
 * the evidence I've gathered so far, especifically the definition of the total function below:

size_t Mat::total() const
{
    if( dims <= 2 )
        return (size_t)rows * cols;
    size_t p = 1;
    for( int i = 0; i < dims; i++ )
        p *= size[i];
    return p;
}

 * we can conclude that:
 *  -   No one dim image:
 *      This is impossible apparently, and the documentation of mat::dims indicate that dim has to be at least two.
 *      If however we supply an empty vector, we can create a 0 dim image! As soon as we supply an element, the
 *      matrix dim would be two.
 * 
 *  -   Two dim:
 *      In this case, the definition of element is the number of pixels in the image. Note that even if the number
 *      of channels is not 1, the matrix returns rows * cols.
 * 
 *  -   Higher dim images:
 *      In such a case, rows and cols are defined as -1, and number of channels MUST be set to 1 in the type of
 *      image. In this case, the total number of elements equals what we have over all dimensions, and opencv
 *      does not consider the third dimension as channel. 
 * 
 * In conclusion, we either have 2D images with channels, or we have higher dimension matrices, but for example no
 * 3d image with 2 channels (this is not possible.) In such a case, perhaps the third dimension is 2, but the 
 * number of channels are (and must be) set to 1.
 * 
 */