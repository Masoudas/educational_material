/**
* As we already know, when returning a stack variable, the function tries to do it using the move constructor.
* But imagine if instead we tried a T& return. Then we'd have be using a new somewhere. This would bring about
* so many problems, such as who would be responsible for deleting the object etc. This is why C++ opted for a
* move constructor (and then copy) constructor when returning stack objects.
*/