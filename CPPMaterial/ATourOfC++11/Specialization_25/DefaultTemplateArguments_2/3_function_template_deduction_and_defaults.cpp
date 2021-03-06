/**
* Me: A gentle reminder. Recall that when using function templates, templates can be deduced. Note that the <>
* can thus be dropped! So for example, when you use sort in std, you never say sort<>(begin, end), but just say
* sort(begin, end). So, when all template parameters can be deduced, there's no need for the brackets! With that
* reminder, we now move to the main discussion.
* 
* Consider the following definition of to function. We don't have to specify the types, and if we had to, it would
* be just the Target type, because it can't be deduced by template argument deductions.
* 
* Me: to here converts a type to a string representation, and then that string representation to an output type.
* 
* Note from the big guy:
* This implementation of to() is a bit heavyweight for combinations of simple types, such as to<double>(int), but 
* improved implementations can be supplied as specializations. Note that to<char>(int) will not work because char 
* and int do not share a string representation. For conversion among scalar numeric types, I tend to prefer 
* narrow_cast<>()
* 
*/

#include <string>
#include <exception>

using namespace std;
template<typename Target = string, typename Source = string>
Target to(Source arg) // convert Source to Target
{
	stringstream interpreter{};
	Target result{};
	if (!(interpreter << arg) // write arg into stream
		|| !(interpreter >> result)) // read result from stream
		//|| !(interpreter >> std::ws).eof()) // stuff left in stream? This line does not work!
		throw "to<>() failed" ;
	return result;
}

