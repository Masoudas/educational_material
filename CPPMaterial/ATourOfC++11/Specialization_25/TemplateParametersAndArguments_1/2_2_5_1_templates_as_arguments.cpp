/**
* So far, whenever we've defined a templated type, we never imposed a condition that it should be templated itself.
* We could for example supply a templated type, but we've never imposed it as a condition. For example, when we
* say:
* template<typename T>
* struct S{
*	T t;
* }
* 
* It's true that t could be for example vector<int>, which is a full type. However, we can't say for example:
* template<typename T, typename W>
* struct S{
*	T<W> t; // Wrong
* }
* 
* This is because T is a full type, and we did not mention that it can be templated itself. So for example, we can't
* pass an int type and a vector type and create the proper vector inside!
* So next, we're going to discuss how we can solve this..
*/