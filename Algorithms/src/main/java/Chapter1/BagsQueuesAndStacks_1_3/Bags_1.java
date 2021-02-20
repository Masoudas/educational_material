package Chapter1.BagsQueuesAndStacks_1_3;

/**
 * It's just a collection of objects, where order of iteration is not important. removing objects
 * is not supported as well. The client of the bag just wants to iterate over the collection.
 * 
 */
public class Bags_1<T> {
    void add(T t){}
    int size(){
        return  0;
    }
    boolean isEmpty(){return false;}

}