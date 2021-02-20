/**
 * sizeof as we know returns the size of a type in number of chars (hence size(char) = 1).
 * 
 * sizeof works mostly at compile time information. This is very important,
 * as we will see below. For compile time entities, because every information about size is available,
 * sizeof returns the size of every entity in char terms. 
 * 
 * The sizeof operator returns the size of a generic as well? Well, 
 * We usually should not work with sizeof at runtime, but rather ask for size directly. For
 * example, when using template T, we can ask for the size right away. Something like
 * template<class T, std::size_t SIZE>. Also, look at this http://www.jonathanbeard.io/blog/2016/04/01/template-type-sizing.html
 * 
 * So here are some questions: What is the size of a pointer? As we know, the size of a pointer
 * depends on the architecture of the system and can be 4 or eight. This is equal for EVERY SINGLE 
 * POINTER OUT THERE (because pointers work indepndently of the object). It's a COMPILE TIME INFORMATION.
 * 
 * What is the sizeof for an array? Depends on whether the array is created at compile time or at runtime.
 * For compile time sizeof(arr) returns the total number of chars an array holds for any array (1D, 2D, ...).
 * For example, 3 ints in a windows machine hold 12 chars. The expression sizeof(arr)/sizeof(arr[0]) always
 * returns the number of elements an array hold. The same expression for a 2 * 3 array returns six.
 * 
 * Now what about a dynamic array (generated at run-time)? In this case, when supplied with the pointer, the
 * sizeof returns the size of the pointer, because no compile time information on size exists.
 * 
 * 
 * Challenge: What's another way of getting the size of an array without sizeof? The answer is given below.
 * What about an n-dimensional array?
 * 
 * For custom in types, 
 * the result is the size of an object of that class plus any additional padding required to place such object in an array.
 */
#include <iostream>
using namespace std;

class A{
    int x;
    int y;
    char c;  
};


void size_of_for_getting_size_of(){
    int* p;
    char* p1;
    long long* p2;
    A* p3;

    int arr[] = {1, 2, 3};
    int size_arr = sizeof(arr) / sizeof(arr[0]);

    cout << sizeof(p) << endl;
    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;

    cout << sizeof(arr) << endl;
    cout << sizeof(size_arr) << endl;
    cout << *(*(&arr)) << endl;

    char arr2[4][3];
    cout << *(&arr2 + 1) - arr2 << endl;
    cout << sizeof(arr2) << endl;

    cout << sizeof(A);

}

/**
 * Here's the idea. The arr is a pointer to an array of n integer pointers. Hence, this pointer plus one is the start of next
 * such array. Hence, if subtract the address of these two elements, we see how many times the pointers have incremented. Hence,
 * we can find the number of elements.
 * 
 * (&arr + 1) is the address of next such array (with that many elements, forget whether they're pointers or actual ints)
 * (Note that (&arr + 1) - arr returns 1, because we're moving ONE such array forward.). In other words, if arr is size n, then:
 * int (*p)[n] = (&arr + 1).
 * 
 * What's a pointer to an array n integer can be implicitly converted to? The pointer to its first element, which in our case
 * is just an int. hence, *(&arr + 1) - arr which is just a subtraction from one int to another gives us the size of the array.
 *  
 * NOTE HOWEVER THAT THIS FUNCTION WOULDN'T WORK :D. WHY? BECAUSE  AS WE KNOW, 1D ARRAYS DECAY TO POINTERS TO TYPE!
 * So this function would simply returns an unkown number (address of pointer plus one is unknown to us)!
 */

int CopyingSizeOfForArrays(int arr[]){
    // (&arr + 1) next position in memory of array of this type.
    // *(&arr + 1) first pointer of this kind for the next array
    return *(&arr + 1) - arr;
}
