/**
 * enum classes are strongly typed, hence as we see in the following, we can't for example
 * assign an integer to them, or assign another enum to them.
 * 
 * However, we can assign an integer explicitly to an enum class. If the value does not
 * exist, the behavior is undefined. Of course, we need to use an static_cast<Type>. Also, to get the
 * int value of an enum we also better  use an static cast.
 * 
 * The size of an enum class is the size of its underlying type.  In particular, if the underlying type
 * is not explicitly specified, the size is sizeof(int).
 */
enum class Traffic_light { red, yellow, green };

enum class Warning { green, yellow, orange, red }; //fire alert levels Warning 
//Warning a1 = 7;//error : no  int->Warning conversion
//int a2 = green;//error : green not in scope
//int a3 = Warning::green; //error : no  Warning->int conversion 
Warning a4 = Warning::green; //OK 
void f(Traffic_light x){
   // if (x == 9) { /*...*/ }//error : 9 is not a Traffic_light
   // if (x == red) { /*...*/ }//error : no red in scope 
   // if (x == Warning::red)  { /*...*/ }//error : x is not a Warning
    if (x == Traffic_light::red) { /*...*/ }//OK
}

/**
 * The enumeration set type by default is int. We could however be specific about it. */
enum class A : char{a}; //sizeof(Warning)==1

/**
 * Of course we can define operations on an enumeration, but they can be defined inside the enum.
 * 
 * Question: Why can't I return a reference here? Because that would imply we can actually
 * change the underlying values. I can however return a const Warning&, which is unnecessary.
 * 
 * We can of course use this operator when a constant is needed, like in a switch statement
 * 
 * case warning1|warning2
 * */
constexpr Warning operator|(const Warning& a, const Warning& b){
    return static_cast<Warning>(((static_cast<int>(a)) | (static_cast<int>(a))));
}