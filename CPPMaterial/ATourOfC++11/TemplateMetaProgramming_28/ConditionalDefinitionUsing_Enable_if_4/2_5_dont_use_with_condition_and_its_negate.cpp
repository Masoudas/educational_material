/**
* The MSVC documentation also says:
*	-	Do not use enable_if to select between implementations at compile-time. Don't ever write one enable_if for 
*		CONDITION and another for !CONDITION. Instead, use a tag dispatch pattern—for example, an algorithm that selects 
*		implementations depending on the strengths of the iterators they're given.
*
*	-	Do not use enable_if to enforce requirements. If you want to validate template parameters, and if the validation 
*		fails, cause an error instead of selecting another implementation, use static_assert.
*
*	-	Use enable_if when you have an overload set that makes otherwise good code ambiguous. Most often, this occurs in 
*		implicitly converting constructors (as the big guy said).
*/
#include <memory>
#include <type_traits>
#include <string>
