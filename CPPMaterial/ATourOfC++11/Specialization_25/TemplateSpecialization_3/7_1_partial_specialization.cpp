/**
* This is from me: As we know, specializationsw can also themselves be templated. Note that when defining them, the type 
* templates must equal the number of templates the specialization has. Then we use the templates inside the specialization
* definition (right after the class name I mean.)
* 
* For example consider below, where the original type has two templates. For specialization that itself has one template,
* we only define one template type, and we're good to go.
* 
*/

template<typename T1, typename T2>
struct S{};

template<typename T2>	// Specialization has only one template
struct S<int, T2>{};

template<>	// No templates are required for this specialization
struct S<int, int> {};

template<typename T1, typename T2>
struct S<T1*, T2*> {};	// Two templates are required here.