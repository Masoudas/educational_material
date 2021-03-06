/**
* A declaration of the primary template is sufficient to allow the definition of a specialization:

template<typename T>
class List; // not a definition

template<typename T>
class List<T*> {
// ...
};

* If used, the primary template must be defined somewhere (§23.7). If the primary template is never 
* instantiated, it need not be defined. This can be used to define a template for which only a fixed set
* of alternative arguments are accepted. If a user specializes a template, that specialization must be
* in scope for every use of the template with the type for which it was specialized. For example:

template<typename T>
class List {
// ...
};

* It is essential that every use of a template for a given set of template arguments be implemented by 
* the same specialization. If not, the type system is broken, so that identical uses of a template in 
* different places may yield different results and objects created in different parts of a program may
* not be compatible. Clearly that would be disastrous, so a programmer must take care that explicit
* specialization is consistent throughout a program. In principle, implementations are capable of
* detecting inconsistent specialization, but the standard does not require them to and some don’t.
* 
* All specializations of a template must be declared in the same namespace as the primary template. If 
* used, a specialization that is explicitly declared (as opposed to generated from a more general template) 
* must also be explicitly defined somewhere (§23.7). In other words, explicitly specializing a template 
* implies that no (other) definition is generated for that specialization.
*/