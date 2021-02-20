/**
* We already have some guesses regarding how a template type can be specialized. For a value template,
* we just define the value. For a template type, we can define a type. 
* 
* Suppose however that a templated type has two templates, and we want to specialize it for one template
* (meaning for example, equivalent types). We need to say X<T,T>, where T is a template. Hence, we define
* the specialization as a template!!!
*/

template<int Val>
struct W { int j = 1; };

template<>
struct W<0> { int j = 2; };	// Specialization of value template.

template<typename T>
struct Z{};

template<>
struct Z <W<0>> {};	// Z is specialized for W<0>

template<typename T, typename U>
struct Y{};

template<typename T>
struct Y<T,T> {};	// Special case where both template types are equivalent.