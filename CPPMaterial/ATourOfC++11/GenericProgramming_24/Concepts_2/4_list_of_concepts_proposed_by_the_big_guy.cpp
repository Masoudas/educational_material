/**
* This section is out of place, but the big guy proposes the following concepts. He's implemented them and they're
* accessible on his website, and he prefers to put them in a namespace called Estd, so that they won't interfere
* with the possible future language mechanisms (available from Cpp20).
* 
* - Input_iterator<X>: X is an iterator that we can use only once to traverse a sequence (forward using ++), 
*	reading each element once only.
* 
* - Output_iterator<X>: X is an iterator that we can use only once to traverse a sequence (forward using ++), 
*	writing each element once only.
* 
* - Forward_iterator<X>: X is an iterator that we can use to traverse a sequence (forward using ++). This is what 
*	a singly-linked list (e.g., forward_list) naturally supports.
* 
* - Bidirectional_iterator<X>: X is an iterator that we can move both forward (using ++) and backward (using --). 
*	This is what a doubly-linked list (e.g., list) naturally supports.
* 
* - Random_access_iterator<X>: X is an iterator that we can use to traverse a sequence (forward and backward) and 
*	to randomly access elements using subscripting and positioning using += and -=. This is what an array 
*	naturally supports.
* 
* -	Equality_comparable<X,Y>: An X can be compared with a Y using == and !=.
* 
* - Totally_ordered<X,Y>: X and Y are Equality_comparable and an X can be compared with a Y using <, <=, > and >=.
*
* -	Semiregular<X>: Xs can be copied, default constructed, allocated on the free store, and are free of minor 
*	annoying technical restrictions
* 
* - Regular<X>: Xs are Semiregular and can be compared using equality. The standard-library containers require 
*	their elements to be regular (Me: especially the default constructible part is important!)
* 
* - Ordered<X>: Xs are Regular and Totally_ordered. The standard-library associative containers require their 
*	elements to be ordered unless you explicitly provide a comparison operation.
* 
* - Assignable<X,Y>: A Y can be assigned to an X using =. (Me: Not necessarily having a common type)
* 
* - Predicate<F,X>: An F can be called for an X yielding a bool.
* 
* - Streamable<X>: An X can be read and written using iostreams.
* 
* - Movable<X>: An X can be moved; that is, it has a move constructor and a move assignment. In addition, an X is 
*	addressable and destructible.
* 
* - Copyable<X>: An X is Movable and can also be copied.
* 
* - Convertible<X,Y>: An X can be implicitly converted to a Y.
* 
* - Common<X,Y>: An X and a Y can unambiguously be converted to a common type called Common_type<X,Y>. This is a 
*	formalization of the language rule for compatibility of operands to '?:' . For example, 
*	Common_type<Base*,Derived*> is Base* and Common_type<int,long> is long
* 
* - Range<X>: An X that can be used by a range-for (§9.5.1), that is, X must provide members, x.begin() and x.end(), 
*	or nonmember equivalents, begin(x) and end(x), with the required semantics.
* 
* Obviously, these definitions are informal. In most cases, these concepts are based on standardlibrary type 
* predicates, and the ISO C++ standard provides formal definitions (e.g., §iso.17.6.3)
*/

