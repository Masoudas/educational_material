/**
 * In non-static functions of the class, this is a POINTER that refers to the current instance
 * (current memory) of the class. Hence, *this is the actual value of the class.
 * 
 * In the example below, we use this to allow method chaining:
 */
class Date {//..
    Date& add_year(int n);//add n years
    Date& add_month(int n); //add n months
    Date& add_day(int n);//add n days};
};

Date& Date::add_year(int n){
    // some operation
    return *this; // No copy operations take place here, because returning by reference uses the actual object, rather than copy it.
}

/**
 * Note that this is an rvalue. This is because we cannot assign to it directly, (Me: because
 * we may imagine that this is a read-only pointer).
 * 
 * In a const member function of class X, the type of this is const  X∗,
 * to prevent modification of the object it self.
 * 
 * Holy Moly! We can actually say delete this. Could be very dangerous I assume. Or may be not.
 * Here's an implementation of a Linked List.
 * 
 */
struct Link
{
    Link* suc;
    Link* pre;
    int data;

    Link* insert(int n){ //inser t x before  this
        return new Link{pre, this, data};   // What does this call?
    }

    void remove()  //remove and destroy this
    {
        if (pre) pre->suc = suc;
        if (suc) suc->pre = pre;
        delete this;}
};
