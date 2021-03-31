/**
* The critical information supplied by the primary template is the set of template parameters that the 
* user must supply to use it or any of its specializations. If we have defined a constraints check for a
* template, the primary template is where it belongs because concepts are something a user cares about and
* must understand to use the template.
* 
* For technical reasons (because the language doesn’t recognize constraints checks for what they are), a 
* constraints check needs to be replicated in every specialization.
* 
* Me: Note that this does not imply that checking is always done by the primary template, and we needn't
* supply the check to specialization, nor that we should or should not do so. Checks in the primary are
* solely checked in the primary, and if we use a specialization, then if needed, the checks should be repeated there too. 
* What the big guy says is that if someone reads the code, the primary template is where they go first, not the 
* specialization!
*/

template<typename T>
class List {
	// static_assert(Regular<T>(), "List<T>: T must be Regular");
};