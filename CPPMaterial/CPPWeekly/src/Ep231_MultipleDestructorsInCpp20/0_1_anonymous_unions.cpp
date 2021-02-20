/**
* We can declare anonymous unions inside a class. A union has the size equal to the largest element size,
* but only the elements defined can be used, and the other ones have meaningless values.
* 
* Why are they useful? Well, take a look at the following examples and judge for yourself
*/
#include <cstdint>

struct xyz {	// 3d points are available as either x,y,z or a vector!
	union {
		struct { int x; int y; int z; };
		int vec[3];
	};
};

struct rgb { // rgb is available as either r, g and b or as a 32 bit value!
	union {
		struct { int r; int g; int b; };

		std::uint32_t val;
	};
};