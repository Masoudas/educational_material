/**
 * Functions using void∗ pointers typically exist at the very lowest level of the system, 
 * where real hardware resources are manipulated.  For example:
 * void∗my_alloc(siz e_t n);          //allocate n bytes from my special heap.
 * Occurrences of void∗s at higher levels of the system should be viewed with great suspicion because
 * they are likely indicators of design errors.
 * Sometimes we want to refer to memory address, without knowing the underlying type. In this
 * case, we use void*. Pointer to functions and pointer to member cannot.
 * 
 * void* can be assigned another void*. void* can be compared for equality, and they can be
 * safely cast. Other operations are unsafe.
 */
void f(int* pi){ 
    void* pv = pi;   //ok: implicit conversion of int* to void*
    //*pv;        //error : can’t dereference void*
    //++pv;       //error : can’t increment void* (the size of the object pointed to is unknown)
    
    int* pi2 = static_cast<int*>(pv);  //explicit conversion back to int*
    //double* pd1 = pv;//error
    //double* pd2 = pi; //error
    double* pd3 = static_cast<double*>(pv);         //unsafe (§11.5.2)
}