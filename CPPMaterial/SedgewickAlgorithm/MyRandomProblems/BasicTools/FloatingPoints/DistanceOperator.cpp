/**
* Write a function that returns true if the distance of two float values is less than one?
* 
* Answer: The point of this exercise is not the fact that we're dealing with floating points. I just
* want to review the concept of how to write the function. Now, we have that |x - y| < a. But this would 
* imply that x - y < a AND -a < x - y. Therefore, we can implement it as follows:
*/

template<typename T>
bool d_less_than(T x, T y, T dis) {
	return x - y < dis && x - y > -dis;
}