package Chapter1.BagsQueuesAndStacks_1_3;

/**
 * We attempt to implement a fixed size stack of string. Go down below.
 */
public class FixedSizeStringStack_4 {
    private String[] stack;
    private int index = 0;

    public FixedSizeStringStack_4(int size){
        stack = new String[size];
    }
    
    public void push(String s){
        if (index < stack.length) stack[index++] = s;

    }

    public String pop(){
        if (index > 0) return stack[--index];
        else return null;
    }

    public boolean empty(){
        return index == 0;
    }
}

/**
 * If we wanted to make this class generic, we would need to create an array of a generic, which
 * as we know is impossible in Java. The work-around is to use an array of objects.
 */
class FixedSizeStack<T>{
    T[] stack;

    @SuppressWarnings("unchecked")
    public FixedSizeStack(int size){
        stack = (T[])new Object[size];
    }
}

/**
 * To make the stack non-fixed size, always when we reach the array half size, we expand it so that the
 * array has enough space. Moreover with pop, one we get to the quarter of the size, we split the array in half.
 * You forgot to check for N > 0.
 * public T pop(){
 *  
 *  if ( N > 0 && N <= stack.length / 4) downsizeArray();
 * }
 */

 /**
  * Avoid Loitering: One thing that Joshua Bloch taught us was that when we pop, the array would keep a reference 
  to the object. So best to set it to null to avoid loitering as well.
  */

