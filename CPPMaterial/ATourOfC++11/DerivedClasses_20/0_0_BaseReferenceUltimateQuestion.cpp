/**
 * What happens in the following code?
 * 
 */
#include <iostream>

class Base {
    virtual void method() {std::cout << "from Base" << std::endl;}

public:
    Base(){std::cout << "base constructor" << std::endl;}
    Base(const Base& base){
        std::cout << "base copy constructor" << std::endl;

    }
    virtual ~Base() {
        std::cout << "Calling destructor ";
        method();}
    void baseMethod() {method();}
};

class A : public Base {
    void method() {
        std::cout << "from A" << std::endl;}
public:
    A(){
        std::cout << "A constructor" << std::endl;
    };
    
    A(const A& other) : Base(other){
        std::cout << "A copy constructor" << std::endl;
      //  std::memcpy(this, other, sizeof(A));
    };

    ~A() override {
        std::cout << "Calling destructor ";
        method();}
};

//int main(void) {
//    Base* base = new A;
//    base->baseMethod();
//    delete base;
//
//    Base base1 = A{};
//    return 0;
//}

/**
 * Answer: When the class is constructed, the base class constructor is called first, then the 
 * class A. Hence we first print from Base, then from A. Note that no cpy constructor is called here, because
 * new does not need a copy.
 * 
 * Second line: Note that a private method is not inherited. Hence, when we call the base method from
 * the reference method, if it has been overwritten, the overwritten version is performed. Hence, here we print
 * from A.
 * 
 * Third: We must remember that if base class destructor is virtual, derived class ALWAYS OVERRIDES it, even when
 * override keyword is not declared. We delete from derived to base. Hence, the dervied class destructor calls from A.
 * Then the base class destructor calls from Base. One other way to think about this is that as the dervied class gets
 * destroyed, calls to methods are reverted back to base class, apparently!
 * 
 * Fourth line: First B const, then A const, then B copy const (after all we're only copying B). Then B destructor,
 * then A destructor, which are like before. What I don't understand is that at the end, base destructor
 * is called twice. Why?
 */