/**
 * To call constructor, Bjarne recommends using {}.
 * 
 * Function arguments can take default arguments, and so do constructors.
 * Bjarne says he likes to give default values a weird one, which he thinks give him 
 * more flexibility. It can be dangerous, but I don't know.
 * 
 * Here's something a bit weird. Suppose I define class A below:
 */
class A{
public:
    A();
};

/**
 * Now, suppose I create an instance of the class called a. I can reinitialize the class 
 * several times. I think this is fine in general, like in modern languages we can define a
 * class reference, and assign several new to it. 
 */
void reinitializing_class(){
    A a{};
    a = A{}; // Think of it as a new class instance. remember that assignment takes place here.
}

