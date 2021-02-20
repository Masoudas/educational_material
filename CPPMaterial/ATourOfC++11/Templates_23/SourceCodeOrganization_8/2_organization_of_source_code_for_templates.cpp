/**
* As the big guy says, "Including template declarations (only) before their use in a translation unit, and defining
* the templates in some other translation unit" does not work. Hence, the big guy proposes two options:
* [1]	Include template definitions before their use in a translation unit.
* [2]	Include template declarations (only) before their use in a translation unit. Include definitions of 
*		templates later in the translation unit (potentially after their use).
* 
* (Me: [1] suggests having the template and its definition in the same translation unit (or a header file I guess),
* so that every time, they're included as an ensemble. [2] suggests that we first include the header, then use the
* templated type, and then finally include the definition, that was provided in a translation unit). 
* 
* An example of approach one is given in the book, where the templated function is directly defined in the header.
* An example of approach two is as follows, where out contains a template type or function:
#include "out.h"
// use out()
#include "out.cpp"
* where out header contains the defintion, and out.cpp contains the implementation. Yep, this approach is kind of
* bizzare. The problem with the first approach is inclusion of the header for material not related to the templated
* type, which increases the compile time. The second approach is vulnerable to definitions inside the TU. For example,
* suppose someone says '#define std MyLib', and then we've used std inside the out method!
* 
* I PERSONALY THINK WE SHOULD USE MSVC's APPROACH, which is discussed next.
* 
* (Me: So we see an important reason why templated functions need to be defined inline. This way, whenever they're
* included, they're inlined, and not separately defined, which makes optimization more likely).
* 
* As a reminder and comparison, note that non-inlined non-templated functions and static members must have a 
* unique definition somewhere inside a translation unit (particularly recall that static members unless they're
* const can't be defined inside the class.)
*/