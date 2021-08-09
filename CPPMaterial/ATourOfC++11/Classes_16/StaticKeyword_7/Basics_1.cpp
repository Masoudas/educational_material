/**
 * A variable that is part of a class, yet is not part of an object of that class, is called a static member. There 
 * is exactly one copy of a static member instead of one copy per object, as for ordinary non-static members.
 * 
 * Similarly, a function  that  needs  access  to  members  of  a class, yet doesn’t need to be invoked for a 
 * particular object, is called a static member function.
 * 
 * If a static member is defined, it has to be INITIALIZED for its memory to be accessible elsewhere. Otherwise for 
 * example in the below class if we define default_date and don't assign a default to it, we'll get an error. Hence,
 * DEFINITION OF STATIC IS NOT INITIALIZATION.
 *  
 * The definition for a static data member shall appear in a namespace scope enclosing the member’s class 
 * definition (See _2 of here).
 * 
 * We can access a static member or function using the object, or using the scope operator (like Date::set_default). 
 * The latter is preferable.
 * 
 * When defining a static member or function outside the class definition, the keyword static should not be repeated.
 */
class Date {
    int d, m, y;
    static Date default_date;
public:
    Date(int dd = 0, int mm = 0, int yy = 0) {};
    static void set_default(int dd, int mm, int yy); //set default_date to Date(dd,mm,yy)
};

Date Date::default_date {16,12,1770};   // Assigning the dafault static value, not using the auxiliary method.

void Date::set_default(int dd, int mm, int yy){} // The keyword static is not repeated.

/**
 Note that here were accessing the constructor with default values, not accessing A.
 /
Date copy_of_default_date = Date{}; // 
void f(Date);

void g(){
    f(Date{});
}

/** 
 * Consequently, we don’t need a separate function for reading the default date. Furthermore, where the target type 
 * is unambiguously a Date, plain{} is sufficient. For example:
 */

 void f1(Date);
 void f2(Date);
 void f2(int);  // Overloading f2.

 void g(){
     // f1({});                //OK: equivalent to f1(Date{}).
     // f2({});                //error : ambiguous: f2(int) or f2(Date)? See _11_5_2
     // f2(Date{});         //OK
 }

 /**
  * In multi-threaded code, static data members require some kind of locking or access discipline to avoid race 
  * conditions. 
  * 
  * Me: Recall that using local_thread allows us to create a static member per thread at least in functions. 
  * Then, who's to say we can't do it with classes!
  */
 