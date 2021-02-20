/**
* The way MSVC has taken care of this problem is to define the templated types as non-header non translation unit
* entities. Consequently, when we include them, they're just placed inside the program without being compiled.
* It's I think a clever idea. The problem however with it is that everytime we include something, then all the
* material from the header is added, and it has to be recompiled! So this is one reason why compilation time is
* very significant compared to other programming languages.
* 
* Keep in mind however that this approach has a certain advantage. Namely, because we have to include templated
* types in every translation unit, this approach of not defining templated types as translation units actually
* saves us one extra compilation (had they been defined vector.cpp for example, the compiler would have compiled
* them too, which is not necessary). Therefore, perhaps defining templated types not as headers and translation
* units is actually a clever idea. We should however ensure that there are no non-templated types inside, so that
* we don't run into problem due to multiple definition of non-templated types. In fact, this is exactly what MSVC
* has done, and there are no '.h' files that contain a templated definition. Conversely, if we check those files
* with no extension that contain code, we see that they have no non-templated type.
* 
* Thanks Microsoft, we always learn a lot from you guys!
*/
#include <vector>