package Chapter1.BagsQueuesAndStacks_1_3;

/**
 * We can implement an stack either using an array, or as we do here using a linked list.
 * The difference here is that the starting node of the linked list refers to the last 
 * element of the linked list.
 * 
 * For the implementation, because we want to follow the convention for a linked list (that is,
 * the last node must contain a null reference), we think of stack as adding an element 
 * to the start of the stack every time a new item is added. Hence, we have the following implementation.
 * 
 */
class Node<T>{
    T item;
    Node<T> next;
}

public class StackAsLinkedList_6<T> {
    Node<T> first = new Node<>();   // The original first contains null reference. It always points to the top of stack.
    int N;  // Number of elements.

    public void push(T t) {
        N++;
        Node<T> oldFirst = first;
        first = new Node<>();

        first.item = t;
        first.next = oldFirst;
    }

    public T pop(T t) throws IllegalAccessException {
        if (first.item == null) throw new IllegalAccessException();
        N--;
        T object = first.item;
        first = first.next;

        return object;
    }

    public boolean isEmpty() {
        return first.item == null;
    }

    public int size(){
        return N;
    }
}
