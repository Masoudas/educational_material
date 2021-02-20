/**
* Imagine now that we have composed two namespaces into a third one. However, there's a nameclash between
* some elements of the dragged namespaces. How do we resolve this problem?
* 
* The answer is, if we use a declarative saying which one of the two we want in the current namespace,
* this problem is resolved.
* 
* When looking into a namespace, names explicitly declared there (including names declared by
* using-declarations) take priority over names made accessible in another scope by a using-directive.
* (Me: In general, being explicit prevails. For example, declaring something explicitly prevails over
* using it. Decalaring a specific use takes over a general declare).
*/
namespace HisLib {
	class String { /* ... */ };
	template<class T>
	class Vector { /* ... */ };
	// ...
}
namespace HerLib {
	template<class T>
	class Vector { /* ... */ };
	class String { /* ... */ };
	// ...
}
namespace My_lib {
	using namespace HisLib; // everything from HisLib
	using namespace HerLib; // everything from HerLib
	using HisLib::String; // resolve potential clash in favor of Hislib
	using HerLib::Vector; // resolve potential clash in favor of HerLib
	template<class T>
	class List { /* ... */ }; // additional stuff
	// ...
}