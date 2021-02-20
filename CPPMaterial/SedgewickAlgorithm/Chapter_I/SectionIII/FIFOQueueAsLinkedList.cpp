#include <exception>
using namespace std;

template<typename T>
struct Node{
    T item;
    Node<T>* next;

    Node(T item) : item(item), next(nullptr){}
};

template<typename T>
class Queue{
private:
    int N;
    Node<T>* first;
    Node<T>* last;

public:
    Queue() : N(0), first(nullptr), last(nullptr){}
    void enqueue(T t);
    T dequeue();
    int size(){return N;}
    bool isEmpty(){return N == 0;}

    ~Queue();
};

template<typename T>
void Queue<T>::enqueue(T t){
    Node<T>* oldLast = last;
    last = new Node<T>{t};

    if (oldLast != nullptr){
        oldLast->next = last;
    } else{
        first = last;
    }
    ++N;
}

template<typename T>
T Queue<T>::dequeue(){
    if (isEmpty()){
        throw std::exception("Stack is empty");
    }
    
    Node<T>* oldFirst = first;

    T item = first->item;
    first = oldFirst->next;

    delete first;

    --N;
    return item;
}

template<typename T>
Queue<T>::~Queue(){
    if (isEmpty()){
        return;
    }

    for (Node<T> node = first; node != nullptr;)
    {
        Node<T> oldNode = node;
        node = oldNode->next;

        delete oldNode;
    }
    
}