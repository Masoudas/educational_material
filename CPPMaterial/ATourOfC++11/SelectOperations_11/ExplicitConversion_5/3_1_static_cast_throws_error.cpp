/**
 * As we already mentioned, static_cast has compile time checks to ensure that we're not converting incompatible
 * types. Therefore, we CAN'T convert a pointer to double to a pointer to int. However, we can convert a double to
 * int, because that's allowed in C++ through a narrowing conversion.
 * 
 */

struct double_wrapper{
    double d;
};

void cant_do_crazy_things_with_static_cast(){
    double result = 10;

    int result_in_int = static_cast<int>(result); // This is fine(ish)
    
    // int* result_in_int_ptr = static_cast<int*>(result); Oops! 
    // double_wrapper* d = static_cast<double_wrapper*>(result);    Ooops! Only possible with C-style unchecked cast.
}