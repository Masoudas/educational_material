/**
* The Enable_if techniques work for template functions (including member functions of class templates and specializations) 
* only. The implementation and use of Enable_if rely on a detail in the rules for overloading function templates. Consequently, 
* it cannot be used to control declarations of classes, variables, or non-template functions. For example:

enable_if<(version2_2_3<config),M_struct>* make_default() // error : not a template
{
	return new Mystruct{};
}

template<typename T>
void f(const T& x)
{
	Enable_if<(20<siz eof<T>),T> tmp = x; // error : tmp is not a function
	Enable_if<!(20<siz eof<T>),T&> tmp = *new T{x}; // error : tmp is not a function
// ...
}

* 
* 
* 
*/