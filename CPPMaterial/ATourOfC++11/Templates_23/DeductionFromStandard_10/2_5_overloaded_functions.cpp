/**
* Regarding function pointers, the standard states:
* 
* "If P is a function type, pointer to function type, or pointer to member function type and if A is a set of 
* overloaded functions not containing function templates, template argument deduction is attempted with each 
* overload. If only one succeeds, that successful deduction is used. If none or more than one succeeds, the 
* template parameter is non-deduced context."
* 
* This implies that if multiple overloads apply, then an error is thrown. In particular, if the char function
* below also returned a char, an error would have been thrown.
*/

template<class T> void accepts_templated_fptr(T(*p)(T)) {};
int g(int) { return 0; };
int g(char) { return 0; };

void using_accepts_templated_fptr() {
    accepts_templated_fptr(g); // P = T(*)(T), A = overload set
          // P = T(*)(T), A1 = int(int): deduced T = int
          // P = T(*)(T), A2 = int(char): fails to deduce T
          // only one overload works, deduction succeeds
}
