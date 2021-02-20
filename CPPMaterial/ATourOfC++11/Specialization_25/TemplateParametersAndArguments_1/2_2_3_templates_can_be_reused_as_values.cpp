/**
* Note that once a template has been defined, it can be reused as value type too.
* 
* In particular, we can specify that the default value must be default constructible.
*/

template<typename T, T default_val = T{} >
void templated_type_requiring_default() {}