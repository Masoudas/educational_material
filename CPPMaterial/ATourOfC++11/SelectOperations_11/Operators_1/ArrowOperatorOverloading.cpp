/**
 * This is one of the weird ones. Consider a.operator->(). As we know, with a normal class, a-> means the underlying value
 * dereferenced from the pointer. But at the same time, note that we can't access this operator through a pointer to a class 
 * (like we normally do with the dereference), but rather through an instance of the class!! So if we returned a type of the 
 * class, then when using this class we would have to say a->.x to access element x. This I'm sure violates some 
 * rule regarding adjacency of operators.
 * 
 * Therefore, we return a pointer to the object. The dereference operator has this property that it starts a loop,
 * until it reaches a pointer, and then dereferences it. So a-> first returns a pointer, then (*a) is applied to ->,
 * and now we have access to the class.
 * 
 * 
 * But then again, note that we can return whatever we want from this operator!
 */
#include <iostream>

using namespace std;
class OverloadDeref{
public:
    int x = 10;

    OverloadDeref* operator->(){
        return this;
    }
};

int main(){
    OverloadDeref o{};

    cout << o->x;
}