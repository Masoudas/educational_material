/**
* For example, when we consider string class, we want this class to be independent of the char type used
* under the hood. If the char type supports a minimal set of conditions, then we can use for example 
* a string with Japanese chars.
* 
* Note in fact that this is what happens with the normal string class. That is, basic_string<char_trait>
* is used with normal chars to create "string" class.
* 
* template<typename C> prefix specifies that a template is being declared and that a type argument C will 
* be used in the declaration. After its introduction, C is used exactly like other type names. 
* The scope of C extends to the end of the declaration prefixed by template<typename C>
* 
* There's no difference between saying class and typename in template declaration. The defined type then 
* can be a class, or a non-class type.
*/