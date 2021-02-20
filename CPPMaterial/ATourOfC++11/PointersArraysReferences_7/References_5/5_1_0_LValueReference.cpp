/**
 * lvalue references MUST ALWAYS be initialized.
 * 
 * Because the value of a reference can't be changed, there are no operators working on reference.
 * We can think of a reference as a constant pointer to the object, which is not separate from the
 * object itself.
 * 
 * Here's something interesting. This initialization is wrong. Why?
 * double &l = 1; // Wrong.
 * 
 * Why? Because l is a reference to an lvalue as we said, but 1 isn't an lvalue!
 * However, with constants, c++ allow us this type of initialization:
 * const double &l {1};
 * It takes the value and makes an implicit  conversion to the type, then puts it in a
 * temporay location of memory, and then puts the address of that memory in l.
 * 
 * Question is, why do we need reference to constants? Note that the reference by itself is constant,
 * hence the constant part always refers to the value. So the value is constant.
 * 
 * As we know by now, the following function changes the value of the reference. It is
 * however better not to write programs that change their arguments, but rather return
 * a new value. The point is that we need to strongly indicate that the arguments are changing.
 */
void f(int& r){
    r++;    // Changes the value of r on the outside.
}