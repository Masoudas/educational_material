/**
* Don't assume that the move operations leave the original object with nullptr. This may be the case with
* some move constructor, but as we saw in 1_, this was not the case with the swap assignment we implemented.
* 
* Note that leaving the original object after move with a valid state is crucial, because the constructor still
* has to function properly. Also as a reminder, remember that setting a pointer to nullptr is a valid state. Why?
* Because delete and delete[] do nothing when faced with nullptr (now we understand why 
* C++ does not throw exceptions on deletion of nullptr :D).
*/