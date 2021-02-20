/**
* The standard says "Type alias is a name that refers to a previously defined type (similar to typedef).
* Alias template is a name that refers to a family of types."
* 
* This statement is fundamental in understanding of aliases. A problem that I usually have is that I tend to define an
* alias for a container iterator in its definition, before actually defining the iterator. This is wrong. As the standard says, 
* an alias is for a type that's already defined. Hence, for example, the following is incorrect:
* 
* Note that the second part of the statement is trivial, indicating that an alias of a template param naturally aliases every
* type refered to by the template.
*/

struct container {
	using iterator = class container_iterator;	// Wrong! When compiler reaches here, it can't find container iterator!
};

struct container_iterator {

};