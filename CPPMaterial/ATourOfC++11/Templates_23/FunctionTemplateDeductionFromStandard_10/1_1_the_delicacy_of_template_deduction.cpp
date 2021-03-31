/** This is me:
* Often, I confuse the rules of template deduction for FUNCTIONS, particularly in the special case of forwarding. 
* The rules however seem to be simple and straightforward.
* 
* In what follows, I'll focus on the section of standard called "Template argument deduction." To understand
* the forward function, check chapter 35, minor utilties.
* 
* Of minor importance is the difference between function templates and class templates. With class templates
* as we may recall, we MUST(ish) specify template type directly (to be able to use templated constructors.) 
* Note: As of C++17, template arguments can be deduced for classes too. See the section on deduction for
* classes.
* 
* A last point to recall is that as we now know famously, once an rvalue reference is created, it becomes an
* lvalue reference (because it points to an object in memory.) We should keep this point in mind when we use
* rvalue templates, and preserving rvalue templates is an important task. We shall show how this is achieved.
* 
* Note that throughout this document, whatever is not in quotation marks is from me.
* 
* The standard reminds us that "Template argument deduction takes place after the function template name lookup 
* (which may involve argument-dependent lookup) and before template argument substitution (which may involve 
* SFINAE) and overload resolution." This is an important point. In particular, if a function has both a 
* templated and non-templated version, first template argument takes place, then overload resolution happens.
* 
*/