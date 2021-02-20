/**
* In this excersie, we intend to get as close to creating an array of Objects (like C#) as possible.
* 
* The official statement of the problem is:
* Write a function that takes any number of elements of any type, 
* which can, in turn, be converted into a common type. The function should also return a 
* container having all the elements converted into that common type, and it should also be fast to traverse.
* 
* Answer: We most definitely have to deal with variadic arguments. Now we have two questions:
* 1- Can we get the number of args in the function at compile time?
* 2- Can we get a common denominator type for the variadic arguments?
*  
* Because the answer to both questions is yes, we shall return an array. This array would be the common
* type, and its size is the number of arguments.
* 
* Question: Why are we not using decltype to compute the return type? Because the type is known (array)
* and need not be calculated.
* 
* Now, we answer the two questions above:
* 1- The number of variadic arguments can be calculated using sizeof...(args). Note again that this a 
* compile time information.
* 2- The common type of variadic arguments can be calculated using the common_type struct in type_traits
* module. Note the use of it, we pass variadic template as common_type<Args...>, and then the type alias
* inside this class has the common type.
* 
* Note finally that to implement this function, we take rvalue reference. Naturally, we need to forward
* this to constructor of array. Note also we pass the entire variadic argument to the constructor of array,
* which uses the initializer list constructor of array.
* 
* Here's another question: How does one use this array of common elements? Specifically, if we didn't want to
* use auto, and actually wanted to know the type? Well, the compiler shows the common type.
* 
* But then again, this does not if I use the forward function. I have no idea why?!
*/
#include <array>
#include <type_traits>
#include <iostream>
#include <algorithm>

using std::cout;

template< typename ... Args>
auto build_array(Args&&... args)-> std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
	using commonType = typename std::common_type<Args...>::type;
	return { static_cast<commonType&&>(args)... };
}

//int main() {
//	auto obj_arr = build_array(1, 1.1f, false); // The common type is double in this case
//	std::for_each(obj_arr.begin(), obj_arr.end(), [](double v) {cout << v << '\t'; });
//
//	//auto obj_arr1 = build_array(1, "My blue pen"); We can't find a common type for int and pointer to constant char.
//}