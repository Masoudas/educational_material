/**
* So imagine using a namespace that has a version number attached to it. This version number changes all the time.
* Using an alias allow us to just declare versioned name once, and shields us against the need to go through
* every use of the versioned name in all of the code base.
* 
* If we use a new version of library here, we just have to change library aliasing.
*/

namespace library_0_0_1 {

}

namespace using_library {
	namespace lib = library_0_0_1;

	// Now use lib only.
}