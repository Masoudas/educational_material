/**
* A destructor is called implicitly when the object goes out of scope or is deleted.
* 
* In some cases however, we need to explicitly call the destructor to ensure that
* loitering objects are deleted. Say for example in a container, when we remove some 
* items, we need to call the destructor of the object (or perhaps node if necessary).
* With construction also, we need to (sometimes) create a copy of the object, or perhaps
* move it into the new position.
*/
template <typename T>
void push_back(const T& a) {
	T* p;	// say this is the pointer of the container.
	new(p) T{ a };	// placement new. Puts the copy into p.
}

template <typename T>
void pop_back() {
	T* p;	// say this is the pointer of the container.
	p->~T();	// Destruct object in the pointer;
	p--;
}