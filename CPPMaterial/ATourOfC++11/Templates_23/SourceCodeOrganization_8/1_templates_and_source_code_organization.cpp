/**
* Introduction of source codes into the source presents a problem. For historical reasons (Jesus history!), we 
* can't separate the definition and implementation of a templated type. In other words, we can't put the defintion
* of a templated type or function in a header file, and then it's implementation in a translation unit.
* 
* Testing this phenomenin is very simple, and we can do it by creating a header file and a translation unit, and
* and then only include the header file somewhere else.
* 
* Let's see how we can solve this problem.
*/