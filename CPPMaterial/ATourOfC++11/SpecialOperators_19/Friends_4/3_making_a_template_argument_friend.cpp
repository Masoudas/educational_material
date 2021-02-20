/**
* It's possible to make the template parameter of the class friend as well. 
* 
* Moreover, a templated type can be our friend as well, in which case we need to define a template parameter as well.
* See chapter 23.
*/

template<typename T>
class friendee {
	// friend class T;	// Putting class here is redundant, and VS actually throws an error!
	friend T;	// T is now our friend.
};

// Befriending a templated type and the bizzare notion it has, eliminating the template!
class fri {
	template<typename U>
	friend class friendee;
};
