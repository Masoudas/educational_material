/**
* The template<> prefix says that this is a specialization that can be specified without a template  
* parameter. The template arguments for which the specialization is to be used are specified in <> 
* brackets after the name. That is, the <void*> says that this definition is to be used as the 
* implementation of every type for which T is void*.
* 
* template<typename T>
* struct type{}
* 
* template<>	// This is not a templated type anymore, but we need to keep interface
* struct type<void*>{}	// Every instance initialized with void* uses this.
* 
* An specialization like type<void*> that itself contains no templates is called a complete specialization.
* That is, there is no template parameter to specify or deduce when we use the specialization.
* 
* Now, contrast this defintion to the following:
* 
* template<typename T>
* struct type{}
* 
* template<typename T>	
* struct type<T*>{}	
* 
* In this case, the specialization itself is templated. Consequently, we repeat the templated type. Now,
* here's the difficult part: the template (in name) in the above example is still T. However, this special
* case is instantiated if we pass pointers (like int*.) The point being implied here is that inside the 
* class, if we wrote for example 'T t', then this t is still an instance of T (an int for example). It is
* not T* (or int*). This is an obvious point, which is evident based on the usuall syntax of templates.
* 
* A specialization with a pattern containing a template parameter is called a partial specialization in 
* contrast to complete specializations
*/