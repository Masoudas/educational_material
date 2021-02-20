/** This is me:
* Imagine we have a class observer, that we want to declare as friend.
* 
* Now consider two scenarios:
* 1-	The class that wants to declare friend is not templated.
* 2-	The class that wants to declare frined is templated.
* 
* For both of these class, we need to say template<typename T> friend class observer. Observe that with this notion,
* we use the class keyword. Hence, we're declaring a new type (regarding observer is already defined). Hence, the
* type being observed is observable by every possible template type of observer (we can't confine it to a particular
* template type).
* 
* There's one exception to this rule. If the observed class is templated, we can state that the observer only
* watch the same template type as the observed, by writing frined observer<T>, where T is the observed template
* parameter. Other than this, THERE'S NO way to allow the observed to be observable by a particular template type.
* 
* Note, however, that the second situation is potentially rare. Consider the implementation of a List<T,Alloc> and 
* Link<T>. Because the types have different number of templates, we need the friend class form. Hence, Link<T>
* cannot be frineds only with List<T>.
* 
* As a final precaution, the above discussion does not depend on the order of definition of observer and observable.
*/

template<typename T>
struct observer {
	void get();
};


struct observable {
	// friend observer<int>; // Even though this compiles, it does not work, and observer can't see 
							// observable.

	//friend observer; Error! Not declaring a template parameter.
	
	template <typename U>
		friend class observer;	// This is the correct version. Observe the use of class, and the lack of
								// template declaration of template in class parameter.

private:
	int private_part;
};

template <typename T>
struct templated_observable {
	friend observer<T>;

private:
	T private_part;
};


template<typename T>
void observer<T>::get() {
	templated_observable<T> t1{};	// Ok. Both classes have the same type, so we can observe.
	T t = t1.private_part;	

	templated_observable<int> t2{};
	//int t2_ppart = t2.private_part; // Error! Impossible to access a templated version with different template
								   	  // parameter.

	observable p1{};
	int t2_ppart = p1.private_part;	// Ok. The class can be observed.
}

template <typename T, typename Alloc>
class List {

};

template<typename T>
class Link { 
	template <typename U, typename Alloc>
		friend class List;	// Can't bind to only list of the same type.
	T t; 
};


//int main() {
//	observer<float> o1{};
//
//	o1.get();
//}
