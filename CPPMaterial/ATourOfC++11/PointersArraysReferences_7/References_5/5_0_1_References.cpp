/**
 * The problem with passing pointers is that we always have to use &x to pass the address.
 * Hence for example, if we were overloading +, then we would need to write one version with
 * +(int, int) and one with +(*int, *int). Also, a pointer points to different objects.
 * Lastly, to access an object we write x->y, whereas . is used for a method. Above all, we have the problem
 * of nullptrs. 
 * 
 * The reference would take care of all of the above. A reference is an alias for an object,
 * and it's written to hold the address of the object. 
 * 
 * You access the reference content with exactly the same syntax as the object. 
 * A reference always refers to the object with which it was initialized.
 * There's no null reference.
 * 
 * The main use of references is for specifying arguments and return values for functions 
 * in general and for overloaded operators.
 * 
 * Just to further stress, references need to be initialized at the point of declaration:
 * int &a; // This is invalid!
 * And by initialization, we imply initialization with a concrete object. rvalue references in particular
 * cannot be initialized like a normal object (more precisely, rvalues)
 * string& s = string{"err"}; // Error! Initializing rvalue ref with temp. 
 * 
 * Note from me: It appears reasonable and logical and safe to assume that when declaring a variable, the var
 * name is in fact an lvalue itself. This shall become handy for interpretation in some corner cases of references
 * in the future!
 */
template<class T>
class vector {
    T *elem;//...
public:
    T& operator[](int i) { return elem[i]; }//return reference to element 
    const T& operator[](int i) const { return elem[i]; }    //return reference to const element
    void push_back(const T& a) {}; //pass element to be added by reference
    //...
};

//void f(const vector<double>& v){
//    double d1 = v[1];       //copy the value of the double referred to by v.operator[](1) into d1
//    v[2] = 7;               //place 7 in the double referred to by the result of v.operator[](2)
//    v.push_back(d1);        //give push_back() a reference to d1 to work with
//}

/**
* Now, we have lvalues, rvalues, and constants and non-constants. To reflect the difference
* between these, We have three kinds of references:
* 
* lvalue reference: Refers to an object (object in the general sense)
* constant reference: Refers to constant objects (and literals)
* rvalue reference: References to objects whose value we do not need to preserve after we have used it.
 */