/**
 * More complicated objects  can  require  more  than  one  value  as  an  initializer.  
 * This  is  primarily  handled  by  initializerlists delimited by {and}.  For example:
 */ 
#include <vector>
void initialization(){
    int a[] = {1, 2, 3};
    
    struct s{int s; char c;}; // An structure
    s s1 = {5, 'c'};  // A form of initializer with equal. We said we need not use this form.
    s s2{5, 'c'};

    std::vector<double> v = { 0.0, 1.1, 2.2, 3.3 }; // This one uses the constructor

}

/** In some cases, function style initialization is preferred (Me: Especially, if we want to use a particular
 * constructor) 
 * 
 * The point is that sometimes using the default constructor in functional method is ambiguous. For example
 * std::vector<double> f() is interpreted as defining a function that returns vector. Hence in this
 * case, we better use {}
 * */
void functional_initialization(){
    std::vector<double> v (10, 3.3 ); // Ten elements, set all to 3.3
}

/** When using auto, a list has its type deduced to std::initializer_list<T>.  
 * For example:
 * 
 * auto x1 {1,2,3,4}; //x1 is an initializer_list<int>
 * auto x2 {1.0, 2.25, 3.5 };    //x2 is an initializer_list of<double>
 * auto x3 {1.0,2}; //error : cannot deduce the type of {1.0,2}
 */