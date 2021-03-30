/**
* In the following rather complex example, we demonstrate how specialization helps reduce code bloat with
* C++ templates. Code bloat is particularly important, because as we may recall, templated types are 
* generated per type. 
* 
* Consider a vector type. Most uses of vector would be with pointers (int*, string*, etc.) Now, to avoid
* code bloat for different types (string*, int*, etc) we need to somehow connect all types that use
* pointers, and bring them under the same roof, so that the same code is generated for pointer types.
* For that, we may recall that every pointer can be converted to a void pointer. So, if we define a base
* class for vectors that contain void pointer specialization, then what we can do is that we can
* put all common operations inside that base class (call it base_vector), then inherit it in the actual
* implementation of vector (for pointers.) That way, most of the burden will be directed to that base class,
* and the templates will be thin covers for that base class.
* 
* This discussion brings us to another point. Note that specialization that are for particular type (like
* base_vector<void*> in our case) are like normal types, and are not templated. Hence, the compiler compiles
* them once, and they don't cause code bloat. If a specialization itself has other templated params, this
* is not the case however (although if we go to the actual implementation of vector for example, we see 
* that there's still a base vector like structure, even though we have templated parameters for allocator
* for example. The reason is that allocators don't change that often, hence having this base class does
* not cause code bloat.) Consequently, this specialization is still put in the 'vector' file, not in another
* translation unit. Note however that for example in our case, we need to put vector<void*> in a separate
* translation unit, and not in a file like 'vector'. Otherwise, there would be a separate implementation of
* basic_vector<void*> in every translation unit that uses vector, which would make the linker mad!
* 
* In any case, we can see the implementation of vector_base. Notice how we use this base class in the
* implementation of vector.
* 
* Another interesting point of interest: Can the specialization inherit vector_base<void*>, but not the
* actual templated interface? By this I mean the actuall 'vector' template would not be a child of vector_base, but,
* one of its specializations (the void* one,) that we're interested in inherits from base_vector<pointer*>. So we'd 
* have something like:
* 
* template<typename T>
* class vector{};	// Does not inherit from base_vector<T>!
* template<>
* class vector<void*> : public vector_base<void*>{}
* 
* Therefore breaking down the hierarchy?
* 
* The answer is NO! and a big NO! This is because this violates the type check, and in this way, we can convert some 
* instances of vector (those that are pointers) to vector_base, but not other instances, which are not pointers (like
* for example an int instantiation!)
*/

template<typename T>
class vector_base { // general vector type
	T* v;
	int sz;
};

template<>
class vector_base<void*> {
	void** v;

	vector_base(int size) {}
	void*& operator[](int i) { return *v; };
};

template<typename T>
struct vector : public vector_base<T> {};

template<typename T>
struct vector<T*> : public vector_base<void*> {
	using base = vector_base<void*>; // aliasing base class name.

	vector(int sz) : base(sz) {}
	T*& operator[](int i) {
		return reinterpret_cast<T*&>(base::operator[](i)); }	// Hiding base class method!
};