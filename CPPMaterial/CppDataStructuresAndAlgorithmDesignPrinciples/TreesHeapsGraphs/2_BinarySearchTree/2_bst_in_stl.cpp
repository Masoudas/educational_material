/**
* Do we have binary search trees in C++?
* 
* In an explicit sense, no. However, both set and unordered_map are implemented in such a way that they use
* binary search trees (or their variants). This is for example one reason why neither work very well with
* repeated keys. In essence, we shouldn't search for a binary search tree, but rather use either of these two
* options
*/