/**
 * This statement is correct in C++, and checks whether d is zero!!! Why? Because we have an implicit
 * cast from 0 to true.
 * 
 * int d;
 * 
 * int m = d ? d : 100; //!!!!
 */