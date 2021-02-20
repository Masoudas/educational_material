/**
* Sometimes when the name of a namespace is too long, we want to aliase that, as we do the name of 
* any normal class. When can do so, with the namespace aliasing approach shown below.
*/

namespace my_very_very_long_namespace {
	int i = 10;
}

namespace using_very_very_long {
	namespace ns = my_very_very_long_namespace;

	void f() {
		int j = ns::i;
	}
}