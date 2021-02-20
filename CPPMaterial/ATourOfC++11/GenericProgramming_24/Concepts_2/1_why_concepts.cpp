/**
* What are a template’s requirements for its arguments? In other words, what does the template code assume about 
* its argument types? Or conversely, what must a type provide to be acceptable as an argument to a template? The 
* possibilities are infinite because we can build classes and templates with arbitrary properties,
* 
* -	Types that provide − but not +
* - Types that can copy but not move values
* - Types for which copy operations does not copy (like the copy on demand types for example.)
* - Types for which == compares equality and others for which compare() does that
* - Types that define addition as a member function plus() and others that define it as a nonmember function 
*	operator+()
* 
* In that direction lies chaos. If every class has a unique interface, it becomes difficult to write templates that 
* can take many different types. Conversely, if each template’s requirements are unique, it becomes difficult to 
* define types that can be used with many templates (Me: I agree that constraining a type to an interface is restrictive.
* On the other hand, defining general concepts could lead to ambiguity, and specialized concepts.)
*/