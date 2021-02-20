/*
* In a copy assignment, we can (or cannot) check for self-assignment. For example, with the matrix 
* implementation discussed in 2, we could have checked for this = &ref. However, if the implementation
* of copy assignment is efficient enough, we don't need to do that. Bjarne says this is the case for
* the two versions of matrix assignment.
*/