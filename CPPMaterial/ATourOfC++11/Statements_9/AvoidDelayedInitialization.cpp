/**
 * If we do something like this:
 * string s;
 * s = "Hey";
 * 
 * Then once we've called the default constructor, and another time the assignment operator, which would
 * slow down the code. Hence, this shall be avoided.
 */

/**
 * What is wrong with this piece of code?
 * 
 * Well? I don't know what error is here. Imagine it's an exception (then where's throw for God's sake?).
 * Image if the error is thrown. If buf is allocated on the heap, then we have memory leak (but it's not allocated
 * with new, so what the hell?). So, how does Bjarne say an overflow occurs here?
 * 
 * On the other hand, if it's a function that just prints, then this whole shrade is wrong, becayse no matter what
 * happens, we assign to buf, so there would be an overflow here.
 * 
 */
//void input()
//{
//int buf[max];
//int count = 0;
//    for (int i; cin>>i;) {
//    if (i<0) error("unexpected negative value");
//    if (count==max) error("buffer overflow");
//    buf[count++] = i;
//}
//// ...
//}