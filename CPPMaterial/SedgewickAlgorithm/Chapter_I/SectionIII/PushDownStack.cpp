/**
 * Here, we implement the push down stack using the linked list
 * 
 * Question: What would happen if instead of using a pointer to next, we actually used next?
 * The code would still work. The only problem however would be that I'd keep an actual copy of
 * everything.
 */
#include <exception>
#include <iostream>

using namespace std;

template<typename T>
struct Node{
    T item;
    Node* next = nullptr;

    Node(T item) : item(item){}
};

template<typename T>
class Stack{
    Node<T>* first = nullptr;
    int N = 0;
public:
    Stack(){}

    void push(T item);
    T pop();
    bool isEmpty() const { return N == 0;}
    int size() const {return N;}

    ~Stack();
};

template<typename T>
void Stack<T>::push(T item){
    Node<T>* oldFirst = first;

    first = new Node<T>{item};
    first->next = oldFirst;
    N++;
}

template<typename T>
T Stack<T>::pop(){
    if (isEmpty()) throw runtime_error("The stack is empty");

    T item = first->item;
    first = first->next;
    N--;
    
    return item;
}

template<typename T>
Stack<T>::~Stack(){
    for (Node<T>* node = first; node; )
    {
        Node<T>* oldNode = node;
        node = oldNode->next;
        delete oldNode;
    }
}

void using_push_down_stack(){
    Stack<int> stack{};
    
    cout << stack.size() << endl;
    cout << (bool)stack.isEmpty();

    stack.push(1);
    stack.push(2);

    cout << stack.size() << endl;

    cout << "Pop first value: " << stack.pop() << endl;
    cout << " Pop second value: " << stack.pop() << endl;

    try
    {
        stack.pop();
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "So the exception was caught" << '\n';
    }

    cout << "Size after popping is: " <<  stack.size() << endl;
    
}
