/**
 * Declaring a membermutableis most appropriate when only a small part of
 * a representation of a small object is allowed to change.
 * 
 * Another way of making a class mutable is through defining an indirection class.
 * 
 * Note that const does not apply (transitively) to objects accessed through pointers or references.
 * The human reader may consider such an object as ‘‘a kind of subobject,’’ but the compiler does not
 * know such  pointers  or  references  to  be  any different  from  any others.  
 * That is,  a  member  pointer does not have any special semantics that distinguish it from other pointers
 * (Me: In other words, this is why cache member in the class below cannot change, but its
 * fields can.)
 * 
 * This is another implementation of the problem in _3.
 */ 
#include <string>

struct Cache {
    bool valid;
    std::string str;
};

class Date
{
private:
    Cache* cache;
    void compute_cache_value() const;

public:
    std::string str_rep() const{
        if (!cache->valid){
            compute_cache_value();
            cache->valid = true;
        }

        return cache->str;
    }
};

