/** 
* me: This topic could have also been called there's no overload resolution when it comes to templates. Only
* exact matches are allowed.
* 
* First my own interpretation of the matter: If we consider the following example, we see that the void* type is
* more specialized than T*. Naturally, the question that arises here is that which specialization is used if I use
* Vector<*int>? My contention is that there's no overload resolution rules like those of a function for example.
* So, if a template exactly matches one thing, that thing is going to be used. In this case, we see that int*
* does not exactly match void*. Moreover, void* is more specialized than T*. Consequently, the Vector<T*> is
* prefered over the void* version.
* 
* In particular, note that Vector<int*> is never considered the Vector<void*> specialization. Why? This is because
* only a void* pointer is initialized with this specialization. Note that it's irrelevant that int* can be implictly
* matched to void*. ONLY EXACT MATCHING IS ALLOWED IN SPECIALIZATION.
* 
* Now, we return to what the big guy says:
* One specialization is more specialized than another if every argument list that matches its specialization 
* pattern also matches the other, but not vice versa (Me: That is to say, one specialization is a subset of 
* another.)
* 
* For example below, every type can be used as a template argument for the most general Vector, but only pointers
* can be used for Vector<T*> and only void*s can be used for Vector<void*>.
* 
* A specialization pattern can be specified in terms of types composed using the constructs allowed for template
* parameter deduction. This shall be discussed later.
*/
#include <iostream>

template<typename T>
class Vector {
public:
	Vector() {
		std::cout << "a";
	}
}; // general; the primary template

template<typename T>
class Vector<T*> {
public:
	Vector() {
		std::cout << "b";
	}
}; // specialized for any pointer

template<>
class Vector<void*> {
public:
	Vector() {
		std::cout << "c";
	}
}; // specialized for void*

//int main() {
//	Vector<int*> v{};
//}