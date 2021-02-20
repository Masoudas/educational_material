/**
* Typically, we want to keep the implementation detail as local as possible. Hence, we use nested types
* to do so.
* 
* However, for templated types this may lead to certain usage complexity that can be avoided if the class
* is not nested. This is because formally, a member of the nested class depends on all the template parameters
* (Me: Not directly, but rather indirectly. For example, if we wanted to scope to Link in the following example,
* we'd need to use both T and Allocator in the parent of link, not link itself.)
* 
* Before we continue, we should point out that one way to overcome this problem is to define the class private,
* and then grant access to it using friends, as will be shown below.
* 
* Consider the following example. The link in a linked-list is an implementation detail, and mostly is treated
* as such. However, it can imply performance cost compared to using a nonlocal Link.
* Especially, note that Link does not depend on allocator. However, List<double, My_ALLOC>::Link and 
* List<double, Other_ALLOC>::Link would be two different types (code bloat, OMG!!!). 
* 
* Hence, we may consider an implementation where Link is outside, so that it will only depend on type.
* 
*/

template<typename T, typename Allocator>
class List_Nested_Link {
private:
	struct Link {
		T val;
		Link* succ;
		Link* prev;
	};
	// ...
};

template<typename T>
class Link_Optimized {	// Everything is private, and can only be accessed by friend.
	friend class List;	// Where's the template parameter?
						// What if we didn't omit the Allocator parameter of the list? See 9_2_2.
	T val;
	Link_Optimized* succ;
	Link_Optimized* prev;
};

template<typename T>
class List_Non_Nested {
	Link_Optimized<T>* first;
	Link_Optimized<T>* last;

	T get_first() {
		return first->val;
	}
};