/**
* A cool thing that I've learned from MSVC is to define a macro for namespace definition. That way, when defining class
* in our namespace, we wouldn't have to tab the definition of everything.
*/

#define MY_NS_BEGIN namespace My_NS {;
#define MY_NS_END };
