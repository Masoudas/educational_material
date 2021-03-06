/**
* Specifying all template arguments can be tedious, particularly for the cases where most of the time the template
* is a particular type. Consider for example:
* 
* template<typename Key, typename Value, typename Compare = std::less<Key>
* map{
*	explicit map(const Compare& comp={});
* }
* 
* This would help us not to supply less everytime we want to use the class. Also notice how a default value is 
* made using this constructor (Me: if wanted a comparator with memory, we can supply our own created compare.)
* 
* The semantic checking of a default argument for a template parameter is done only if that default argument is 
* actually used. In particular, as long as we refrain from using the default template argument less<Key>, we can 
* compare() values of a type X for which less<X> wouldn’t compile. This point is crucial in the design of the 
* standard containers (e.g., std::map), which rely on a template argument to specify default values
*/