/**
* As we stated, in cases where a branch of the metaprogram fails, we better not use aliases. 
* 
* Alternatively, we can introduce a Delay type function to delay evaluation of a type function until its use. Consider the
* following rather interesting implementation:

template<typename<typename...> class F, template...args>
using Delay = F<args>;

* This implementation is quite fascinating. We use template template argument to act as a function pointer, then we pass
* the arguments to it using variadic templates. As such, it's like we're getting a function pointer together with its
* arguments. Hence, we can write

conditional<std::is_integral<T>::value, Delay<make_unsigned, T>, Error<T>>

* Now, why would this be helpful? I've no idea! Delay is evaluated right away, giving us make_unsigned<T>. Then what?
*/

