/**
* It's possible to alias elements after they've been composed. This is not generally a good idea though,
* because we don't want to have two names to refer to the same type.
* 
* Also note how the templated type is being aliased. Recall that we can't alias a templated type just
* by its class name.
* 
* Consider his and here lib from 2_3 of this section. We can write:
namespace Lib2 {
	using namespace His_lib; // everything from His_lib
	using namespace Her_lib; // everything from Her_lib
	using His_lib::String; // resolve potential clash in favor of His_lib
	using Her_lib::Vector; // resolve potential clash in favor of Her_lib
	using Her_string = Her_lib::String; // rename

	template<class T>
		using His_vec = His_lib::Vector<T>; // rename
	template<class T>
		class List {  }; // additional stuff
	// ...
}
*/