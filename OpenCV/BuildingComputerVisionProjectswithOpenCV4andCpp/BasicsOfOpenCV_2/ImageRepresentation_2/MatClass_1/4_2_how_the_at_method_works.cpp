/** This is me:
 * If we peek at the implementation of the at method, we see that it essentially is a pointer conversion method.
 * In particular, dropping the CV_Assertions that are at the beginning of the method, we see that the only line
 * of code is:
 
template<typename _Tp> inline
_Tp& Mat::at(int i0, int i1)
{
    return ((_Tp*)(data + step.p[0] * i0))[i1];
}

 * The idea is very simple then. The pointer to the first element of pixel is converted to a pointer of type _Tp.
 * Hence, suppose for example _Tp is a double, then the conversion returns the value of a double at that given
 * location (the conversion to a pointer first and then value through indexing is actually quite fun.)
 * 
 * Next, consider the case where _Tp is a Point3i (see next how to iterate over multi-channel images). Such a 
 * class would have three ints in the beginning of the memory. Hence, if we convert pointers as we do above, a
 * new object is created whose memory is the same as that of underlying pixels! This is a quite clever manipulation
 * of pointers. At the same time, I don't know if this is something the big guy would recommend or not!
 */