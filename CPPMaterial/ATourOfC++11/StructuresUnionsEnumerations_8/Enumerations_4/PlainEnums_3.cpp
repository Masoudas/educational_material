/**
 * We can have unnamed enums, mostly in a class. We now see why they're useful. They can
 * be accessed without the name inside the scope (see Basics_1). Hence, we can directly access
 * their values.
 * 
 * Note that with plain enums, a cast TO int is safe, but a cast FROM integer to enum is not safe,
 * and is not allowed. This is somewhat natural. Because if the value is out of range, then what?
 * So naturally, any operation that involves an integer is not allowed too.
 */
enum my_e {e1 = 1};
// my_e e2 = 1; Not possible

/**
 * Also, take a look at this weird declaration of enum, where we define the enum outside the namescop,
 * hence, the need to use the scope operator.*/
namespace A{
    enum Class_Enum;
}

enum A::Class_Enum{Two};



