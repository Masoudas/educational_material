/**
* So far, we've only considered types. But we should know that function templates can also be specialized.
* 
* Specialization is also useful for template functions. However, we can overload functions, so we see less specialization. 
* Furthermore, C++ supports only complete specialization for functions, so we use overloading where we might have tried 
* partial specialization.
* 
* Me: To further elaborate, say we have a method that takes a template, life template<typename T> f(T), and we wanted to
* do something special for int. We could either say
* 
* template<> f<int>();  // Or
* f(int);
* 
* Both of these are fine, but the second one uses the overload resolution, hence it's preferable. The only issue that
* arises with the second one is that if it's included several times, then a linker error may happen. However, there are
* cases when specialization is handy also. In particular, if we want to define a particular operation for pointers for
* example.
* 
*/