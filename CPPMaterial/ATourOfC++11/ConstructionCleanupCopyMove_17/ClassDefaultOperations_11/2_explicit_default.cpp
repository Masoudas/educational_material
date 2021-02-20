/**
* We can be explicit about which default operations we're going to use, by declaring =default for the class.
* 
* The following two versions of gslice are equivalent. We prefer the less verbose version. We avoid defining 
* default operations for ourselves, because some optimization will be lost.
*/
class gslice_v1 {
	gslice_v1() = default;
	gslice_v1(const gslice_v1& ref) = default;
	gslice_v1(gslice_v1&& ref) = default;

	gslice_v1& operator=(const gslice_v1&) = default;
	gslice_v1& operator=(gslice_v1&&) = default;

};

class gslice_v2 {

};