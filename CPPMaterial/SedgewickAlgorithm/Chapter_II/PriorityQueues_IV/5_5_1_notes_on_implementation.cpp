/**
* We can add a resize operation so that when number of nodes go beyoned a certain threshold, then the array
* is resized.
* 
* As another point of interest, if the user of priority queue changes the node values outside the structure, the
* structure of the tree must change. This is why we normally move elements, or get a copy of them with C++.
* Note however when getting reference, we have to check the integrity of the tree. This would decrease performance
* though, which is why it's better be avoided.
*/