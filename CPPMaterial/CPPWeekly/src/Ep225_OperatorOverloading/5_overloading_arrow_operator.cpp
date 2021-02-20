/**
* As we already know, the arrow operator has a recursive property. It goes so far as finding a pointer,
* and then dereferences it. Now because we use the -> operator with the class instance itself (rather
* than pointer to class), we return this.
* 
* In any case, here's an implementation (adjacent) of a unique pointer. Note how interestingly we can use
* the variadic argument to instantiate the object inside the constructor!
* 
* (Just a side note on unique_ptr: What if I gave this baby an array? Either there's a deleter method
* which gets the deleter of this object, or we're gonna have to delete a chunk of memory directly).
*/
#include <string>

template<typename T>
struct unique_ptr {
private:
	using _Tp = T*;
	_Tp _ptr;

public:
	unique_ptr(const _Tp ptr) : _ptr{ptr} {}
	
	template<typename ...Args>
	unique_ptr(const Args...args) { 
		_ptr = new T{ args... };	// Cool.
	}

	unique_ptr(const unique_ptr&) = delete;	// Don't allow copy 
	unique_ptr(unique_ptr&&) noexcept = delete;	// Don't allow move

	unique_ptr& operator=(const unique_ptr&) = delete;
	unique_ptr& operator=(unique_ptr&&) noexcept = delete;

	_Tp operator->() noexcept {
		return _ptr;
	} 

	_Tp operator->() const noexcept {
		return _ptr;
	}

	~unique_ptr() {
		delete _ptr;
	}
};

void using_unique_ptr() {
	using std::string;
	 
	string* str = new string{ "Say hello!" };
	unique_ptr<string> ptr{ str };

	ptr->clear();	// Using the arrow operator.

	unique_ptr<string> ptr1{ "My baby is a baby" };

	string str1{ "This is wrong" };
	//unique_ptr<string> ptr1{ &str }; // This line will throw an exception upon destruction. Why?
									   // Why you ask? Because the object is on the stack you idiot :D!


}

//int main() {
//	using_unique_ptr();
//}