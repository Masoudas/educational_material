/**
* Suppose that we want to be friends with a templated type. We cannot directly make friends with a templated
* type. Instead, we have to use a template declaration. For example, the link class wants to be friends
* with List. The list has two types, while link has one type. Therefore, we declare List a friend, by 
* declaring a templated friend. Unfortunately, we can't make Link<T> friends with List<T>!
* 
* Bjarne says:
* 
*	Friend classes are designed to allow the representation of small clusters of closely related concepts. 
* A complicated pattern of friendship is almost certainly a design error.
*/


template<typename T>
class Link {
	template<typename U, typename A>
	friend class List;

	T t;
	// ...
};

template<typename T, typename A>
class List {
	Link<T>* first;

	T first_elem() {
		return first->t;
	}
};