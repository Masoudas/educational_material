/** The is me:
* As a reminder, don't forget that presence of function in function (template) over loading may cause unresolved
* call. Hence, be careful about optionals. For example, the following overloads is a receipe for disaster, as
* any call with one parameter causes error, because optional can be ignored.
* 
* In fact, recall that there's no rule in overload resolution saying if the number of arguments is equal, then
* choose the function. We don't choose based on the number of arguments.
*/

template<typename T>
void with_optional(T t1, int x = 10){}

template<typename T>
void with_optional(T t2){}