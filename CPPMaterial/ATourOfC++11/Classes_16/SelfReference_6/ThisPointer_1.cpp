/**
 * In non-static functions of the class, this is a POINTER that refers to the current instance (current memory) of 
 * the class. Hence, *this is the actual value of the class.
 * 
 * In the example below, we use this to allow method chaining.
 * 
 * Me: Why is this a method? Well, if it were an object, it would have contained a copy of the class. Moreover, because references
 * were introduced later in C++, they couldn't define this as a reference. Hence, we're stuck with pointers.
 */

class Date {//..
    Date& add_year(int n);//add n years
    Date& add_month(int n); //add n months
    Date& add_day(int n);//add n days};
};

Date& Date::add_year(int n){
    // some operation
    return *this; // No copy operations take place here!
}

/**
 * Note that this is an rvalue. This is because we cannot assign to it directly, (Me: because we may imagine that 
 * this is a read-only pointer. Quite interesting!)
 * 
 * In a const member function of class X, the type of this is const X*, to prevent modification of the object 
 * itself. (ME: Shouldn't we say const pointer to const X? This would have made more sense.)
 * 
 * We can actually say delete this. Here's an implementation of a Linked List that does so!
 * 
 */
struct Link
{
    Link* suc;
    Link* pre;
    int data;

    Link* insert(int n){ //insert x before  this
        return new Link{pre, this, data};   
    }

    void remove()  //remove and destroy this
    {
        if (pre) pre->suc = suc;
        if (suc) suc->pre = pre;
        delete this;
    }
};
