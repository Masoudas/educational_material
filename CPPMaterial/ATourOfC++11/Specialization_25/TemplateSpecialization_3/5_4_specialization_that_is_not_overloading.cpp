/**
* The big guys says "How does a specialization differ from overloading? From a technical point of view, they differ because 
* individual functions take part in overloading whereas only the primary template takes part in specialization. However, I 
* can't think of an example where that makes a practical difference"
* 
* Me: Although as I discussed, the only difference is in the organization of the program, which I discussed in 5_1.
* 
* There are a few uses of function specializations. For example, we can select among functions taking no arguments:

template<typename T> T max_value(); // no definition
template<> constexpr int max_value<int>() { return INT_MAX; }
template<> constexpr char max_value<char>() { return CHAR_MAX; }

template<typename Iter>
Iter my_algo(Iter p)
{
	auto x = max_value<Value_type<Iter>>(); // works for types with specialized max_value()
}

* So using the template argument, we get the particular overload we seek from above.
*/
