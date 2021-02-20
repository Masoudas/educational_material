/**
 * 
 * If we're accessing a class through its pointer, it's possible to manipulate private data
 * members! Another way is explicit type conversion ( ME: I think it means we can define a class that
 * has the same definition, make every field public, and assign the class with private members to it.
 * But I may be wrong).
 * 
 * Not good C++!!!
 * 
 * Note that the private and public keywords can be repeated:
 * class{
 *  public:
 *      ... 
 *  private:
 *      ...
 *  public: 
 *      ...
 *  
 * };
 */