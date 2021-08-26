/**
 * To indicate to the compiler that the state of a class is not going to change inside the function, we use the const decorator 
 * after the class name.
 */

#include <string>

class Date {
  int d, m, y;
public:
  int day() const { return d; }
  int month() const { return m; }
  int year() const { return y; }
  
  void add_year(int n);//add n years//...

  // This is not accepatable void f{} const {y++;} // Compiler calls error
};

/**
 * Of course we can pass a constant reference to an object in a function as void f(const Date&).
 * We can't modify the variable in that case.
 */

/**
 * Sometimes a member function is logically constant, but physically (i.e, in memory), the class state may change.
 * For example in the Date class, we want to keep a cache string representation of date. The method that returns it is
 * constant, but class state changes.
 * 
 * The problem here is that we need to check if cache is valid inside the method, and create the string. This however 
 * can't be done!!! Such problems could be solved through brute force using a cast, for example, a const_cast. 
 * However, there are also reasonably elegant solutions that do not involve messing with type rules. 
 * See mutableModifier_3.cpp
 * 
 * (Me: Question: How do you return the string, in such a way that copy constructor is not called?
 * Answer: a very simple way is to use const string&. This is possible because non-constant values
 * can be assigned to constant references. Another way is a pointer to constant.)
 */
class Date1 {
public://...
  std::string string_rep() const;//string representation
private:
  mutable bool cache_valid;
  mutable std::string cache;
  void compute_cache_value(); //fill cache
  
  //...
};


