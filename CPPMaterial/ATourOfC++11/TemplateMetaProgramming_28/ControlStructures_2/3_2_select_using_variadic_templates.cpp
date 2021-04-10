/**
* The following is one of the most amazing pieces of code I've seen, which we use to select among types. 
* 
* To begin, note that we can accept as many types as we desire using variadic arguments. Now consider the problem of 
* aliasing only the nth variadic argument. What we need to do is to separate that nth type from the variadic pack. For
* that, we recall that if we have a pack, then somehow assigning it to a new template type <typename T, typename... Cases> 
* would isolate that parameter. So now, consider defining the primary template as follows:

template<unsigned i, typename... Cases>
struct select;

* If i = 0, we can have the following specialization:

template<typename T, typename...Cases>
struct select<0, T, Cases...>{
	using type = T;
}

* Now, note that with this specialization, when we instantiate with 0, we return the first type. Now, how can we choose 
* the second type? Instead of a complete specialization, we do the following trick:

template<typename T, typename...Cases>
struct select<1, T, Cases...> : select<0, Cases>{}

* Amazing, isn't it! We see that we've removed the first parameter here. Now, because we inherit from select<0>, that
* class would be returning the next parameter is type, which is the second in the list! Now, the problem is evident. For
* the nth case, we need to inherit from (n-1)th case. However, that one would be made using n-2, ... till we reach 0. But
* then zero would have chosen the nth argument as we desired.
* 
* In conclusion, we have the following fantastic piece of code, which must be cheriched. Damn this is cool!
* 
* There also doesn't seem to be such a class in the type_traits header!
* 
*/

template<unsigned i, typename... Cases>
struct select;

template<typename T, typename... Cases>
struct select<0, T, Cases...> {	// Unpacking is node using three dots after the definition.
	using type = T;
};

template<unsigned n, typename T, typename... Cases>
struct select<n, T, Cases...> : select<n-1, Cases...>{};
