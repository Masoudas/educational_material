/**
 * As we already know, == is not defined by default for a class. Let's not forget that!! So it's not 
 * like we can compare the reference of two classes in C++ (we have to use runtime info).
 * 
 * For basic_string, we have the following comparison:
 * 
 * a == b:  The strings are equal lexicographically.
 * a != b; not of previous !(a==b)
 * s<s2 Is s lexicographically before s2?
 * s<=s2 Is s lexicographically before or equal to s2?
 * s>s2 Is s lexicographically after s2?
 * s>=s2 Is s lexicographically after or equal to s2?
 */
