/**
 * To be able to modify a class member inside a constant function, we use the modifiable keyword.
 */
#include <string>

using std::string;

class Date {
public://...
    string string_rep() const;//string representation 
private:
    mutable bool cache_valid;
    mutable string cache;
    void compute_cache_value() const {};//fill (mutable) cache
    //...
};

// Now we can define string_rep() in the obvious way:
std::string Date::string_rep() const{
    if (!cache_valid) {
            compute_cache_value();
            cache_valid = true;
    }
	return cache;   // Copy constructor is called here!
}