/**
 * Initialization  can be done in one of the following forms. The bracket version is strongly
 * recommended by Bjarne:
 * 
 * int v1 {1};
 * int v2 = 10;
 * int v3(10);
 * int v4={10};
 * 
 * Initialization with {} does not allow narrowing, that is:
 * 1- An integer cannot be converted to another integer that cannot hold its value.  For example,char to int
 *  is allowed, but not int to char.
 * 2- A floating-point value cannot be converted to another floating-point type that cannot hold its value. 
 *  For example,float to double is allowed, but not double to float.
 * 3- A floating-point value cannot be converted to an integer type. Hence int v {1.3} throws an error,
 *  whereas normally it would be truncated!
 * 4- An integer value cannot be converted to a floating-point type.
 * 
 */
#include <string>
#include <vector>
using namespace std;

void initialization_with_brackets(double val, int val2){
    int x2 = val; //if val==7.9, x2 becomes 7
    char c2 = val2; //if val2==1025, c2 becomes 1

    //int x3 {val}; //error : possible  truncation
    //char c3 {val2}; //error : possible  narrowing
    char c4 {24};//OK: 24 can be represented exactly as a char
    //char c5 {264};//error (assuming 8-bit chars): 264 cannot be represented as a char
    //int x4 {2.0};//error : no double to int value conversion//...
}

/* When using auto, however, we prefer '=', (Me: because of ambiguity between single list and int
* auto v {99}; Is it an int, or a list? It is actually a list, but we might think of it as int.)
*/

/**
 * For class types, we know that _class c1(10) calls the constructor with one argument (function
 * style construction), whereas _class c1 {10} (default initialization) initializes the type with value 10
 * (Me: Its field, which should be an integer I guess)!
 * With classes, when we want to use a constructor, we better directly use the 'new' keyword and call the constructor.
 * 
 * Most types however don't have this problem. For example vector<String> v1("String") is wrong, 
 * whereas vector<string> v2{"String"} is fine.
 */

/**
 * There's a difference between uninitialized local variables and objects (which are 
 * created on heap or free store), and global names, namespace variables, local static or
 * static members.
 * 
 * All the latter are initialized with {} if not already initialized.
 * 
 * The local vars and objects are not initialized, unless they're user defined types with constructors.
 * 
 * Just initialize everything!
 */

void never_leave_a_variable_uninitialized(){
    int x;//x does not have a well-defined value 
    char buf[1024]; //buf[i] does not have a well-defined value
    int *p {new int};   //*p does not have a well-defined value
    char *q {new char[1024]};       //q[i] does not have a well-defined value
    string s;//s=="" because of string’s default constructor
    vector<char> v;//v=={} because of vector’s default constructor
    string *ps {new string}; //*ps is "" because of string’s default constructor//...
} 
