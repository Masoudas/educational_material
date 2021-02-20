/**
* This problem came up when I was working with on the problem of finding the nth element of a container using divide 
* and conquer algorithms, as discussed in the book 'C++ Data Structures and Algorithm Design Principles,' chapter
* four.
* 
* The problem I wanted to solve was to write an iterator that returns every fifth element of the underlying container
* using an iterator to that container. In this exercise, I'll try and iterate over every element, but using the
* wrapper container, because the point is not choosing the fifth element.
* 
* What caused the issue was that I wasn't able to use C++'s internal operators (such as advance, next or distance)
* to get the element I was seeking. I later found out I need to add a couple of other features to the iterator, so
* here we are.
* 
* In what follows we shall discuss each.
*/