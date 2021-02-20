/**
 * As we know, function that are defined in class definition body are inline by themselves.
 */

/**
 * The compiler can make recursive functions inline. For example consider the implementation of Fact below. A clever compiler
 * might inline this function to a certain depth, normally up to level 7. (say what now?)
 */
inline int Fact(int n){
    return n > 1 ? Fact(n) : 1;
}