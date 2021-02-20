/**
 * Without getting into detail, let's imagine this practical example.
 * We want to implement an iterator for an Array class.
 * 
 * So let's say we define a (private) class called _Array_Iterator. The idea of the iterator is this:
 * 
 * 1- An iterator has a template that indicates the class it's iterating on. Hence _Array_Iterator<_Class>.
 * 2- The class being iterated on returns an identifier called iterator, which is _Array_Iterator<_Class>. 
 * To define this identifier, we publicly say using iterator = _Array_Iterator<_Class>;
 * 3- Let's say iterator instance is itr. *itr must return the element at the position itr referes to.
 * In other words, itr acts as a pointer when used in conjuction with operators such as ++, --, != and *.
 * 4- The class being operated on (Array here) has two methods, begin and end. begin returns an iterator 
 * (which for all intents and purposes a pointer) to the first and last element + 1.
 * 
 * Here's the question: How do we pass the pointer of the array class to the iterator?
 * 
 * 
 */
#include <memory>
#include <iostream>
using namespace std;

template<typename Array>
class _Array_Iterator{
public:
    using _Type = typename Array::ValueType;    // Why do we need to write typename here?
    using _Ptr_Type = _Type*;
    using _Ref_Type = _Type&;

    _Array_Iterator(_Ptr_Type ptr){
        this->ptr = ptr;  
    }

    _Ref_Type operator*(){
        return *ptr;
    }
    
    void operator++(){
        ++ptr;
    };

    bool operator!=(_Array_Iterator other_itr){
        return this->ptr != other_itr.ptr;
    }
    
private:
    _Ptr_Type ptr;
};

template <typename T>
class Array{
private:
    T *ptr;
    int size;

public:
    using iterator = _Array_Iterator<Array<T>>;
    using ValueType = T;
    
    Array(int size){
        this->size = size;
        ptr = new T[size];
    }

    T& operator[](int i){
        return *(ptr + i);
    }

    iterator begin(){
        return iterator{ptr};   // A copy takes place here though
    }

    iterator end(){
        return iterator{(ptr + size)};
    }
};


int main(){
    Array<int> arr{3};

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    Array<int>::iterator begin = arr.begin();
    Array<int>::iterator end = arr.end();

    for ( ; begin != end; ++begin){
        int x = *begin;
        cout << "Next element: " << x << endl;
    }



}

