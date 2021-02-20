package Chapter1.BagsQueuesAndStacks_1_3;

import java.util.Iterator;

/**
 * The queue can also be implemented using a linked list.
 * 
 * First, we need to keep the first element to be able to access to it.
 * Moreover, we need to keep a last element to be able to add to the list. Now,
 * we can ask for the first element in the constructor, or we can check
 * everytime an element is put whether we need to put it in the first element.
 * 
 * A good question: What should happen if a client uses enqueue or dequeue while iterating
 * over the queue? The code should throw a ConcurrentModificationException. I think this can be
 * done by checking the size of the queue during every iteration for example.
 */
public class QueueAsLinkedList_7<T> implements Iterable<T> {
    Node first;
    Node last;
    int N;

    private class Node {
        T item;
        Node next;
    }

    public boolean isEmpty() {
        return first == null;
    }

    public boolean size() {
        return first == null;
    }

    public void enqueue(T item) {
        Node oldLast = last;

        last = new Node();

        oldLast.item = item;
        oldLast.next = last;

        if (isEmpty())
            first = last;
        else
            oldLast.next = last;
        N++;
    }

    public T dequeue() throws IllegalAccessException {
        if (isEmpty())
            throw new IllegalAccessException();

        T item = first.item;
        first = first.next;

        if (isEmpty())
            last = null;
        N--;
        return item;
    }

    @Override
    public Iterator<T> iterator() {
        return new QueueIterator();
    }

    private class QueueIterator implements Iterator<T>{
        Node current = first;
        @Override
        public boolean hasNext() {
            return current.next != null;
        }

        @Override
        public T next() {
            T item = current.item;
            current = current.next;

            return item;
        }

    }
}
