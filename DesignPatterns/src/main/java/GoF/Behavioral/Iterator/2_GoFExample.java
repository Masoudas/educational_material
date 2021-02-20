package GoF.Behavioral.Iterator;

import java.util.function.Predicate;

/**
 * In this example, we try and implement an two external iterators, one for
 * front to back iteration and one for end to front iteration. The list class
 * provides enough methods to make iteration possible.
 * 
 * So first we define an iterator interface, to make all sorts of iteration
 * possible. Then we can implemet ListIterator and ListBackwardIterator for
 * example.
 * 
 * The problem with actually having List as an implementation is that our
 * iterator is committed to one implementation. This is why we need to define an
 * abstract List, to ensure that this is not the case. That way, the
 * AbstractList has to provide an Iterator factory method.
 * 
 * By an internal iterator, we mean an iterator whose iteration occurs inside
 * the iterator. We normally pass a method to such iterators to perform a task
 * for us. This behavior in Java is implemented by the iterable interface.
 * Here we have another option for the internal iterator as well. This would be to
 * override the interface for every operation that we want. But the first
 * method is more appropriate here.
 * 
 * But let's implement an interal iterator.
 */

class List<T> {
    T[] list;

    public T getItem(int count) {
        return list[count];
    };

    public int count() {
        return list.length;
    }
}

interface Iterator<T> {
    public boolean isDone();

    public void next();

    public T currentItem();

    public T first();
}

class ListIterator<T> implements Iterator<T> {
    List<T> list;
    int count;

    ListIterator(List<T> list) {
        this.list = list;
        this.count = 0;
    }

    @Override
    public T currentItem() {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public T first() {
        return null;
    }

    @Override
    public boolean isDone() {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public void next() {
        // TODO Auto-generated method stub

    }

}

abstract class AbstractList<T> {
    public abstract T getItem(int count);

    public abstract int count();

    public abstract Iterator<T> gIterator();

}

/**
 * This is the internal iterator interface.
 */
interface InternalIterator<T>{
    public void forEach(Predicate<T> predicate);
}

// Just an implementation of a predicate for my piece of mind.
class predicate implements Predicate<Integer>{

    @Override
    public boolean test(Integer t) {
        return t > 5;
    }

}

