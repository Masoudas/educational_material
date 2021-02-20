/**
* As in mathematics, an axiom is something we can’t prove. It is something we assume to be true. In the context of 
* requirements for template arguments, we use "axiom" in that sense to refer to semantic properties.
* 
* We use an axiom to state what a class or an algorithm assumes about its set of inputs. An axiom, however expressed, 
* represents an algorithm’s or class’s expectations of (assumptions about) its arguments.
* 
* We cannot in general test to see whether an axiom holds for values of a type (that is one reason we refer to them 
* as axioms).  Furthermore, an axiom is only required to hold for the values actually used by an algorithm. For 
* example, an algorithm can carefully avoid dereferencing null pointers or copying a floating-point NaN. If so, it 
* could have axioms that require pointers to be dereferenceable and floating-point values to be copyable. 
* Alternatively, axioms can be written with the general assumption that singular values (e.g., NaN and nullptr) 
* violate some precondition, so that they need not be considered.
* 
*/