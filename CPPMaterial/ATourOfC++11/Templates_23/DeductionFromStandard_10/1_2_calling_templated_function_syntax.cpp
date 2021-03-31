/** Still me:
* As a reminder, note that because function templates can be deduced, the brackets that are used to specify
* templates can be empty, or can be totally omitted.
* 
* template<typename T>
* void f(T t);
* 
* f<int>(5);
* f<>(5);
* f(5);
*/