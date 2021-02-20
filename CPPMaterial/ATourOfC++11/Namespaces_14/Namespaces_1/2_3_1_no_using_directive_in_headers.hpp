/** This is me:
* 
* To further illustrate why we shouldn't have using directives in a header file, consider this example.
* If we use this header anywhere else, the using directive will be included, leading to the fact that if
* any name clashes with those of stl, a compilation error occurs.
* 
* If we want to use members of a namespace in a header file, it's best to use them explicitly.
* I don't even think we should have using declaratives inside header files, because inclusion of them in
* another file my cause conflict in that file!
* Keep headers as clean and as simple as possible.
*/

#include <string>

using namespace std;	// Could be disastorous if this file is included somewhere else.

void string_manipulator(string);

void correct_string_manipulator(std::string);

