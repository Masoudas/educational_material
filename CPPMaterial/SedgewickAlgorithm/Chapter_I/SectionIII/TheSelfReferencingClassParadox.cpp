/**
 * Here's a question. With Node classes, we know that we have to give the pointer to the next node. Why can't we just
 * define the node class like this?
 * template<typename T>
    struct Node{
        T item;
        Node<T> next;

        Node(T item) : item(item){}
    };

 * The answer is that while the compiler tries to create an instance of next, it has to create another instance node
 * for next, which in turn needs another instance, and we have an infinite loop. This however is not the case with
 * pointers, as I would have to only use the a pointer (an integer essentially), to a memory location.
 * 
 * So now we understand why we need to actually use references with self-referencing classes.
 */
