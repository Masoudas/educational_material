package Chapter1.BagsQueuesAndStacks_1_3;

/**
 * A  linked list is a recursive data structure that is either empty (null) or 
 * a reference to a node having a generic item and a reference to a linked list.
 * 
 * To implement a linked list, we we need to implement a node object, which contains
 * the data, and the link to the other node. Such data structures (with no method) are
 * called Records.
 * 
 * Note that we also have a doubly linked list, which holds a reference to previous element
 * and next. This type of list apparently is rarely used.
 */

class Node<T>{
    T t;
    Node<T> next;
}

public class LinkedList_5 {
    Node<String> node1;
    Node<String> node2;
    Node<String> node3; // Note that the final node has null in next.

    public void AddingElementToStart() {
        /**
         * We could say: node0 = new Node<>();
         * node0.next = node1;
         */
    }

    public void addingNodeToLastElement() {
        // This one is also easy as pie.
    }

    public void removingElementFromStart() {
        // The first element content is set the content of the second element content.
    }

    public void removingElementFromEnd() {
        // The one before last element is set to null (assuming we don't need to traverse the list)
    }

    public void removingElements() {
        // To remove an element, we must set the reference to the element in the previous node
        // of node we want to remove to the next one. Of course the poblem here is that we have to traverse the 
        // list.
    }

    public void linkedListIterator(){
        // It's very easy to iterate over a linked list, and it's very natural.
        for (Node<String> n1 = node1; n1.next != null; n1 = n1.next) {
        }
    }
}
