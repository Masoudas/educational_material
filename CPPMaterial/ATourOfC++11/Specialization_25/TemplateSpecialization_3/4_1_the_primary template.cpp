/**
* When we have both a general definition of a template and specializations defining implementations for 
* specific sets of template arguments, we refer to the most general template as the primary template. The 
* primary template defines the interface for all specializations (§iso.14.5.5). That is, the primary 
* template is the one used to determine if a use is valid and takes part in overload resolution. Only 
* after a primary template has been chosen are specializations considered. The primary template must be 
* declared before any specialization.

template<typename T>
class List<T*> {
	// ...
};

template<typename T>
class List { // error : primary template after specialization
// ...
};

* The critical information supplied by the primary template is the set of template parameters that the
* user must supply to use it or any of its specializations.
*/

