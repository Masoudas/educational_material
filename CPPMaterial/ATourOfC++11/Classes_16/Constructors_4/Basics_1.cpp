/**
 * To call constructor, Bjarne recommends using {}.
 * 
 * Function arguments can take default arguments, and so do constructors.Bjarne says he likes to give default 
 * values a weird one, which he thinks give him more flexibility. It can be dangerous, but I don't know.
 * 
 * Now, suppose I define class A below:
 */

class A{
public:
    A();
};

/**
 * Now, suppose I create an instance of the class called a. I can reinitialize the class several times (me: using
 * the assignment operator). 
 */
void reinitializing_class(){
    A a{};
    a = A{}; // Think of it as a new class instance. remember that assignment takes place here.
}

