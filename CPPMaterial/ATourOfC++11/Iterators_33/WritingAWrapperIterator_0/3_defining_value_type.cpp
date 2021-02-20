/**
* One other alias we need to define is the type of value the iterator iterates over. Moreover, the pointer and 
* reference types need to be defined using aliases. Notice that once we know the value type, we can define the
* reference types using the value type alias.
* 
* The name of these aliases should be:
* - value_type: For values
* - reference: For references
* - pointer: For pointers.
* 
* Again, we don't need to memorise these. We just have to check them under the definition of vector iterators.
* 
* Note finally that for the wrapper, we only drag the names from the underlying iterator.
*/
#include <xutility>

class an_int_array_iterator {
public:
	using iterator_category = std::contiguous_iterator_tag;
	using value_type = int;
	using pointer = value_type*;	// Notice here I don't say int*, because now I know the value type.
	using reference = value_type&;	// Just like above.
};

template<typename _Itr>
class iterator_wrapper {
public:
	using iterator_category = typename _Itr::iterator_category;	// Aliasing the type of the iterator to be wrapped.
	using value_type = typename _Itr::value_type;	// Here, I just drag the aliases of the underlying iterator.
	using reference = typename _Itr::reference;
	using pointer = typename _Itr::pointer;
};
