/**
 * For some reason, at the end of class definition we need to put a semicolon. 
 * Note however that we don't need to do this at the end of functions of the class. 
 * 
 * We know the age old difference between classes and structs. Classes need to be sophisticated, hence 
 * every member by default has private access. 
 * 
 * As we know, the scope operator :: is used when we want to define a function operation outside the 
 * class definition.
 * 
 * class Date {
 * public:
 *      void f();
 * }
 * 
 * void Date::f(){//}
 * 
 * A member class that is defined inside a class (not just declared) there, is considered inline. Hence,
 * only petite functions should be written there.
 * 
 */

/** Bjarne says we can do the following, but I don't think it's a very good idea.
 * We can do the declaration in class definition (no implementation), 
 * and then just define the method. This seems to be fine too.
 */
class Date {
public:
    void add_month(int n) { m+=n; }//increment the Date’s m//...
private:
    int d, m, y;
};
 
// Or outside in here!
//inline void Date::add_month(int n)  //add n months
//{   m+=n;      //increment the Date’s m
//}


/**
 * Can class members be references that can be assigned in 
 * constructors? Nope! Because initialization of references cannot be delayed.
 * Hence, if they're reference types, they need to be initialized at once.
 */


/**
 * We can access members of a class by . directly, or by -> with pointers. 
 * The static members outside the class can be accessed with the scope operator
 * */
class A{
public:
    static int x;
};

//int main(){
//    int y = A::x;
//}




