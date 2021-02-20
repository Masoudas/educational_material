/*
* Imagine a scenario where an enitiy is defined in a file. Then it's repeated twice by inclusing,
* once directly and once through including a file that has that header included.
"grandparent.h"
struct foo{};

"parent.h"
#include "grandparent.h"

"child.h"
#include "grandparent.h"
#include "parent.h"

// Now child has two copies of foo!

* To avoid this scenraio, we can:
* 1-	use #pragma once. This however is not a standard solution
* 2-	define header guard #ifndef GRANDPARENT_H #define GRANDPARENT. This way, when child includes parent,
*	we recursively go to grandparent and will see that GRANDPARENT_H is defined, hence they don't re-include
*	it in the source file.
* 
* The second approach still has the problem of naming clash, possibly with third party libraries. Hence, most
* compilers support #pragma once.
* 
* But this discussion is not complete! Continue the followin.
*/