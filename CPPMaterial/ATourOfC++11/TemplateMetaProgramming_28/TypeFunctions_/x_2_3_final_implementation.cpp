/**
* Considering the definition of both On_Heap and Scoped, and the definition of conditional, it's now easy to implement our
* Obj_Holder class.
*/

#include <type_traits>
#include <string>

template<typename T>
struct On_heap {
	On_heap() : t{ new T{} } { } // allocate
	~On_heap() { delete t; } // deallocate

	T& operator*() { return *t; }
	T* operator&() { return t; }

	On_heap(const On_heap&) = delete; // prevent copying
	On_heap operator=(const On_heap&) = delete;

private:
	T* t;
};

template<typename T>
struct Scoped {
	T& operator*() { return x; }
	T* operator->() { return &x; }

	Scoped(const Scoped&) = delete; // prevent copying
	Scoped operator=(const Scoped&) = delete;
private:
	T x; // the object
};

constexpr int on_stack_max = sizeof(std::string);

template<typename T>
struct Obj_Holder {
	using type = std::conditional_t<sizeof(T) <= on_stack_max, Scoped<T>, On_heap<T>>;
};
