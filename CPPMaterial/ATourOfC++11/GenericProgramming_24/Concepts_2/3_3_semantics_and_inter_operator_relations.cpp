/**
* Aside from the syntatic requirements we have discussed so far (like a type must provide the copy operator, or
* that it has the == operator), we also require that:
* 
* 1- These operations have the right semantics
* 2- There's a proper relationship between the operators.
* 
* For example, imagine a type that provides a copy. We need to guarantee that for this type, the result of a copy
* is equal to the original copy. Therefore, T{v} == v, where we have used both the copy and the equality operator.
* 
* As another example, for the standard library, we have that:
*	- The result of a copy compares equal to anything the original compares equal to (a==b implies T{a}==T{b}) and 
*	  the copy is independent of its source (§17.5.1.3).
*	- A less-than comparison (e.g., <) provides a strict weak order
* 
* As we can see, these requirements cannot be expressed in terms of mathematical or programming requirements. 
* Therefore, we need to express these requirements in plain English. This is exactly what is normally being done
* in the standard.
*/