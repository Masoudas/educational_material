/**
* Let's start with a simple yet useful case, initializer_list. The standard lays this ground rule:
* "Template argument deduction attempts to determine template arguments (types for type template parameters Ti, 
* templates for template template parameters TTi, and values for non-type template parameters Ii), which can 
* be substituted into each parameter P to produce the type deduced A, which is the same as the type of the 
* argument A, after adjustments listed below.
*
* If there are multiple parameters, each P/A pair is deduced separately and the deduced template arguments are 
* then combined. If deduction fails or is ambiguous for any P/A pair or if different pairs yield different 
* deduced template arguments, or if any template argument remains neither deduced nor explicitly specified, 
* compilation fails."
* 
* To elaborate, assume that we have i = 0, ..., N templates, which could be templates (Ti), template templates 
* (TTi) and value templates (Ii). Now imagine for each i, we have j = 1, ..., M parameters (call them P types), 
* where equivalently we supply M types for (call them A type) types. So, we use A types, to deduce P types, and
*  then we use P types to deducte T (if possible). 
* 
* As an example, consider the following:
* template<typename T>	// Note that N = 1 in this case.
* void f(T t1, T t2);
* 
* f(1, "c-string");
* 
* In this example, we have two argument types (A), which are A1=int and A2=const char*. Now for these, the Ps
* (or the type of each argument) is deduced as P1 = int and P2=const char*. Now, from the culmination of these,
* we have that P1 and P2 don't have a common subtype. Therefore, the template T1 (as defined above) cannot be
* deduced.
*/
