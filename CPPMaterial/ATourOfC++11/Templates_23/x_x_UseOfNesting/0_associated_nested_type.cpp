/** 
* Here's something interesting. A nested type is sometimes used outside the class. Hence, it's
* associated with the class. 
* In the example below, I define Iterator to be dependent on on T. When it's generated for the class,
* it will be for the particular template. Hence, I can use without any issues. There's no need to define the
* template parameters for the iterator.
* 
* But notice how Bjarne defines his iterator. And it doesn't work! Why? Perhaps, he's just trying to indicate
* that Iterator depends (upon scoping from the container class) on both T and Aloc.
* 
* 
* The point however is that when I try to access the iterator of a certain type, even though allocator
* is not used for that type, I have to bring it in the defintion (saying container<int, int>::Iterator,
* and not container<int>::Iterator). Hence, we can see that for each allocator, a new nested class is defined,
* and I can't assing iterators of one type of allocator to another, even though for example both are of type 
* double.
* 
* One thing that should be pointed out here is that if we tried to Iterator using its own template parameter,
* then everytime we generated the iterator (or used it outside in a function argument) a separate one would have
* been created for its own templates, and independent of the type being used. It's not a good idea in terms of both
* code bloating, and consistency of the T and iterator type.
*/

template<typename T, typename Aloc>
class container {
public:
	class Iterator {
	public:
		T elem() { return T{}; }
	};

	Iterator begin() { return Iterator{}; }

};

template<typename T, typename Aloc>
class bjarne_container {
public:
	class Iterator {
	public:
		T elem() { return T{}; }
	};

	// Iterator<T, Aloc> begin() { return Iterator{}; } Bjarne defines the iterator like this, But it doesn't work here!
};

void using_container_iterator() {
	container<int, int> c1{};
	container<int, int>::Iterator iterator = c1.begin();
	iterator.elem();
}

//int main() {
//	using_container_iterator();
//}