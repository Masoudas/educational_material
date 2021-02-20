/**
* In what follows, we try and implement a linked list. A couple of points are of interest:
* 
* 1- Note that an iterator to the last element is constructed by passing nullptr. This is fairly obvious,
*	because the end is indeed nullptr, but it alluded me for a moment there!
* 2- Note that the post-increment operator accepts an int, but that does not imply that we can write itr + 3.
*	The int is there to just distinguish between pre and post increment operators. Another thing to note about
*   this operator is that we don't return a reference to temp, just the temp, which takes care of the famous
*   problem I had as to why we return an object on the stack by reference.
* 3- Notice that the equality operator for iterator is defined as a friend function inside the iterator. This
*   operator in and of itself is important for comparing begin!=equal. Adding an operator as a friend is a way
*   of accessing private elements, whilst keeping the free function nature of the operator. (See Ep.225 of 
*   CPP weekly).
* 4- As is always the case, we need to override the copy and move constructor. Don't forget that as big Bjarne
*   says, whenever a class has a pointer invariant, the copy and move semantics, together with the destructor
*   need to be overridden.
* 5- Here's a thought: The move constructor here is going to remove a node from the original list, and needs to
*   create new ones in this list. This would imply memory allocation, which implies throwing an exception. So, 
*   should the move constructor be defined as noexcept or not? This was a trick question son :D. When we move,
*   we move the resources from one class to another. Therefore, we just need to make sure that the head pointer
*   in the moved class has the same value as the pointer of the to move class.
*/

#include <iostream>
#include <algorithm>
#include <initializer_list>

struct singly_ll_node
{
    friend class singly_ll; // This does not work with typename!
    friend class singly_ll_iterator; // This does not work with typename!

    singly_ll_node(int data, singly_ll_node* next) : data{ data }, next{ next }{}

private:
    int data;
    singly_ll_node* next;
};

struct singly_ll_iterator {
    using node = singly_ll_node;
    using node_ptr = node*;
private:
    node_ptr ptr;
public:
    singly_ll_iterator(node_ptr p) : ptr(p)
    {
    }
    int& operator*()
    {
        return ptr->data;
    }
    node_ptr get()
    {
        return ptr;
    }

    singly_ll_iterator& operator++()     // pre-increment
    {
        ptr = ptr->next;
        return *this;
    }
    singly_ll_iterator operator++(int)    // post-increment
    {
        singly_ll_iterator result = *this;
        ++(*this);
        return result;
    }

    friend bool operator==(const singly_ll_iterator& left, const singly_ll_iterator& right)
    {
        return left.ptr == right.ptr;
    }
    friend bool operator!=(const singly_ll_iterator& left, const singly_ll_iterator& right)
    {
        return left.ptr != right.ptr;
    }
};


class singly_ll {
public:
    using node = singly_ll_node;
    using node_ptr = node*;
private:
    node_ptr head = nullptr;
    int N = 0;
public:
    void push_front(int val) {
        auto new_node = new node{ val, nullptr };
        if (head != nullptr)
            new_node->next = head;
        head = new_node;
        ++N;
    }

    void pop_front() {
        auto first = head;
        if (head) {
            head = head->next;
            delete first;
            --N;
        }
        else {
            throw "Empty ";
        }
    }

    singly_ll_iterator begin(){
        return singly_ll_iterator(head);
    }

    singly_ll_iterator end(){
        return singly_ll_iterator(nullptr);
    }

    singly_ll_iterator begin() const{
        return singly_ll_iterator(head);
    }

    singly_ll_iterator end() const{
        return singly_ll_iterator(nullptr);
    }

    int size() const {
        return N;
    }

    [[NoDiscard]] bool empty() const {
        return size() == 0;
    }

// Constructors
    singly_ll() = default;

    singly_ll(const std::initializer_list<int>& list) { // Does it have to be const reference?
        std::for_each(std::rbegin(list), std::rend(list), [=](int v) {this->push_front(v); });
    }

    singly_ll(const singly_ll& ref) {
        if (!ref.empty()) {
            auto it = ref.begin();
            head = new singly_ll_node{ *it, nullptr };
            auto last_node = head;

            for ( it++; it != ref.end() ; it++)
            {
                auto node = new singly_ll_node{ *it, nullptr };
                last_node->next = node;
                last_node = node;

            }
        }
    }

    singly_ll(singly_ll&& ref) noexcept : N{ ref.N }, head{ref.head} {
        ref.head = nullptr;
    }

// Destructor
    ~singly_ll()
    {
        if (head != nullptr) {
            while (head != nullptr) {
                auto oldNode = head;
                head = head->next;
                delete oldNode;
            }
        }
    }
};

void testing_singly_ll() {
    singly_ll ll{ 1, 2, 3, 4 };

    singly_ll ll1{ ll };

    std::for_each(ll1.begin(), ll1.end(), [=](int v) {std::cout << v << '\t'; });
}

//int main() {
//    testing_singly_ll();
//}
