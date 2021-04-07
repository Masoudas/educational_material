/**
* A predicate is a function that returns a boolean. If we want to write functions that take arguments that are types, it 
* seems obvious that we'll like to ask questions about the arguments' types. For example: Is this a signed type? Is this 
* type polymorphic (i.e., does it have at least one virtual function)? Is this type derived from that type?
* 
* The answers to many such questions are known to the compiler and exposed to the programmer through a set of 
* standard-library type predicates
* 
* Reminder: POD (Plain Old Data) as we may recall are structures that contain data only (possibly pointers too.) For these,
* no constructor or destructors are defined. For such types, it's much faster to copy memory explicitly than to use copy
* ctors. Note that built-in types themselves are considered POD.
* 
* The standard contains a is_pod predicate that allow us to determine if we're dealing with such types, which therefore
* allow us to copy them more seemlessly. Note that a pointer if existed in POD in this case would be copied by value of
* course, which is perhaps what we intended.
* 
* The std::is_pod predicate is one of the many provided by the standard library. Since the rules for being a POD are 
* tricky, is_pod is most likely a compiler intrinsic rather than implemented in the library as C++ code. The following
* example demonstrates how to copy by checking we're dealing with a POD or not.
* 
* me: Note the following on this implementation:
*	-	 Note one: First, the big guy didn't ask for the size of the object in the first instance. I added that myself! 
*		 Saying copy size * n, rather than just n. May God forgive me for this atrocity!
* 
*	-	 Note two: the condition the big guy uses is not constexpr, which is odd to me. I guess it's fine not to make the 
*		 condition constexpr, but I'm going to make it as such anyway. Because afterall, it's best to make this decision
*		 at compile time.
* 
* Something to note about the implementation below is that we used is_pod_v to get the boolean true or false of whether
* or not a type T is pod or not. This is fine, but we can also call is_pod as a function, which we shall discuss next.
*/
#include <type_traits>
#include <memory>

template<typename T>
void copy(const T* src, T* dest, size_t t, int n) {
	if constexpr (std::is_pod_v<T>) {
		std::memcpy(src, dest, t * n);	// If I dare big guy!
	}
	else {
		for (int i = 0; i < n; i++)
			dest[i] = src[i];
	}

	if (std::is_pod<T>()) {

	}
}