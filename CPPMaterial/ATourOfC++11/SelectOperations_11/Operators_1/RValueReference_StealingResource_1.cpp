/**
 * (Me: Simply put, means take the reference and steal the resources. Mostly used in copy
 * constructores.)
 */

/** For example, a normal copy constructor without rvalue reference is something like this.
 *  We need to copy the string from the other reference to make it available to this class.
 *  Simply put however, an rvalue reference steals the resource from other object. Hence, after 
 * assignment, the original resource would point to null.
*/
class foo {
    public :
        foo(foo const& other){
        this->length = other.length;
        this->ptr = new int[other.length];
        copy(other.ptr, other.ptr + other.length, this->ptr);
        }

    public :
        foo(foo const&& other){
        this->length = other.length;
        this->ptr = other.ptr;
        other.length = 0;
        other.ptr = nullptr;
        }
}
