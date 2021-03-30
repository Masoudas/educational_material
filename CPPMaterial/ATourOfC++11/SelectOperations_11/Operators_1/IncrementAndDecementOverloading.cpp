/**
 * As we know, ++x takes no ints (per se), whereas x++ is x = x + 1;
 * 
 * So in a class, we can overload prefix increment by writing operator++() and postfix increment by
 * writing operator++(int); The int inside is just for distinguishing the two operators.
 * 
 * In a non-member function, because we need to indicate with the pre and post increment are working on,
 * we ask for a reference to the type they'are working on. We ask for a reference because we want to change
 * the value of the underlying type. Naturally there's no return here.
 * See the examples below. 
 * 
 * If we decide to return with the increment or decrement operator, then we can write expressions like 
 * d = ++c; We usually prefer to overload it with a return type. 
 * If we decide to return, as we discussed in the introduction to increment and decrement, we need to 
 * return a temp object for post increment and decrement. This would imply that we have to make
 * a copy of the object.  But then the question  is, who's going to manage the memory of that object?
 * Well, if the resources are a simple integer, there's no need. Otherwise, the answer is not trivial :D
 * As of now, the following gives me an error saying I'm returning a temporary.
 * 
 */
#include <iostream>
#include <list>
using namespace std;

class Increment{
public:    
    int x = 0;

    Increment& operator++(){
        ++x;    
        return *this;   // This is prefix increment. There's no problem here.
    }

    /**
     * For post, we need to create a temp. We're using the copy constructor here. Wouldn't the object be temporary though?
     * I'm going to have to say yes, because the allocation is not on heap. But somehow this work, and everywhere in STL,
     * they do this, and don't use new!
     * 
     */
    Increment& operator--(int w){
        Increment temp = *this;
        --this->x;

        return temp;
    }
};

void inc_dec_examples(){
    Increment c;
    Increment d;
    Increment e;

    d = ++c;
    cout << "This should print 1: " << c.x << endl;

    e = c--;
    cout << "e has same value as ++c, so should print 1: " << e.x << endl;
    cout << "This should print 0: " << c.x;
}