/**
 * Types and type aliases can be members of a class. By types, we mean for example an
 * enum or class. If they're public, they can be accessed via scope operator.
 * 
 * A nested class has access to members of the outside class, including private, IF PASSED
 * A REFERENCE OF THE ENCLOSING CLASS. Otherwise, it just has access to the types and
 * static members (Me: For example, in f() below, we pass a reference of Tree, and not we can
 * even access the private members of Tree). The outer class however can't access the inner class parameters, 
 * but has no notion of a current object of the enclosing class.
 * 
 * Bjarne says member class are more of a notion, however member aliases are important when it comes
 * to generic programming. enums are good for not polluting the name scope, and are an alternative to
 * enum classes.
 */

template<typename T>
class Tree {
public: 
    using value_type = T;//member alias
    enum Policy { rb, splay, treeps }; //member enum
    class Node {//member class
        Node *right;
        Node *left;
        value_type value;
        public:void f(Tree*);
    };
    
    Node *top;
    public:void g(const T&);//...
};

template<typename T>
void Tree<T>::Node::f(Tree *p){    // Ok. Double scope here!
    // top = right; //error : no object of type Tree specified
    p->top = right;//OK 
    value_type v = left->value;               //OK: value_type is not associated with an object
}
