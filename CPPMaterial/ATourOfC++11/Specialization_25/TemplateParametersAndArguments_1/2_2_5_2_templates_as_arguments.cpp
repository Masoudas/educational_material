/**
* To declare a template as a template parameter, we must specify its required arguments.
* (Me: we have function and class templates. Now, we have a TEMPLATE PARAMETER, and we need it to have templates
* itself. So, we need a template for template parameter).
* Note that the expression we used to define the templated type when expanded looks something like this:
* 
* template<typename> typename CONTAINER
* 
* So, other than adding the 'template<typename>,' the rest is the same as defining a normal templated type.
* 
* As we can see below, there's also another element to using template as template argument. That is, we need to 
* alias the templated type itself, so that it can be supplied to the template argument. Otherwise, Imagine writing:
* 
* container_creater<int, std::vector> vec_container;
* 
* The problem with the above code is that std::vector requires its template parameters, otherwise it's not a fully
* defined type, and we get an error. Therefore, we need the aliasing to supply the templated type.
* 
* Only class templates can be template arguments.
* 
* The big guy says "The common case in which a template needs only a container or two is often better handled by
* passing the container types" (Me: In other words, don't use this technique for the example discussed below!)
*/
#include <vector>
#include <list>

template<typename TYPE, template<typename> typename CONTAINER>
struct container_creator{
	CONTAINER<TYPE> container{};
};

template<typename T>
using my_vec = std::vector<T>;

template<typename T>
using my_list = std::list<T>;

void defining_templated_template_arguments(){
	container_creator<int, my_list> list_container{};
	container_creator<int, my_vec> vector_container{};
								
}

// Passing two templates
template<typename TYPE, template<typename, typename> typename CONTAINER>
struct _double_container_creator {
	CONTAINER<TYPE, TYPE> container{};
};
