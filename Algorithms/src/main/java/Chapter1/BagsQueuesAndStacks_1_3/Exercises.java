package Chapter1.BagsQueuesAndStacks_1_3;

import java.io.File;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Date;
import java.util.Iterator;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;
import java.util.TreeSet;
import java.util.stream.IntStream;
import java.util.stream.Stream;



class Three{
    /**
     * a is Ok.
     * b is not Ok. Because we need to have put 6 before 4.
     * c is ok, need to put five before 2.
     * d is ok.
     * e is ok if we put 0 1 2 3 4 5 then pop till 1, then put 6 7 8 9 then pop again.
     * f is not ok, because after poping 8, we need to pop 7.
     * g is not ok. After poping 3, we need to pop 2.
     * h is ok. we put 0, from then every two that we put, we pop two numbers.
     */
}

class Four{
    public static boolean isBalanced(String str){
        if (str == null || str.length() == 0){
            return true;
        }

        Stack<Character> stck = new Stack<>();
        boolean isNotBalanced = false;
        for (int i = 0; i < str.length() && !isNotBalanced; i++) {
            char c = str.charAt(i);

            if (c == '{' || c == '(' || c == '[') stck.push(c);
            else if (stck.isEmpty()){
                isNotBalanced = true;
            }
            else {
                char last = stck.pop();
                if (last == '{' && c != '}'){
                    isNotBalanced = true;
                }
                if (last == '(' && c != ')'){
                    isNotBalanced = true;
                }
                if (last == '[' && c != ']'){
                    isNotBalanced = true;
                }
            }
        }

        return !isNotBalanced && stck.isEmpty();
    }

    public static void main(String[] args) {
        System.out.println(isBalanced("[]}"));
    }
}

class Five{
    /**
     * What does the code fragment do?
     * We see that at each iteration, we calculate the remainder to two. Then we devive by two.
     * Hence, we are calculating the bit presentation.
     */
    public static void method() {
        int N = 0;
        Stack<Integer> stack = new Stack<Integer>(); 
        while (N > 0) {   
            stack.push(N % 2);   N = N / 2; 
        } 
        for (int d : stack) System.out.print(d);
    }
    
}

class Six{
    /**
     * The first while deques (the item that came first), and puts it in a stack. Hence, it changes the order
     * in the sense that it now becomes a LIFO. So the last in the queue is now the first in stack.
     * 
     * So now, the last in queue is being put first in the queue. So the order of the queue has changed.
     * Conclusion, if we want to change the order of a queue, we should pas it through a stack!
     * 
     * However, passing a stack through a stack in and of itself changes the order of the stack.
     */
}

class Seven{
    /** We can keep a refernece to the last item, or just return it. */
}

class Eight{
    /** we know that if x elements are in the stack, the size is x*4 */
}


class Nine {
    /**
     * There's an implicit assumption here, and that is that a paranthesis is used when there are
     * only two expressions, something like (()*()). Hence for example something like (() * () * ())
     * is not accepted with this problem. 
     * 
     * If we look at it this way, now we see that the problem is solvable! in the sense that when we reach
     * a right paranthesis, we have an expression to calculate. Hence that expression together with its operator
     * form a ().
     * 
     * To extend it to the three paranthesis case, we just need to write a for loop it seems.
     */
	private static String getInfixExpression(String input) {
		
		Stack<String> operands = new Stack<>();
		Stack<String> operators = new Stack<>();
		
		String[] inputValues = input.split("\\s"); // Break on \s, or white space
		
		for (String value : inputValues) {
		    if (value.equals("+") 
					|| value.equals("-") 
					|| value.equals("*") 
					|| value.equals("/")) {
				operators.push(value);
			} else if (value.equals(")")) {
				String operator = operators.pop();
				String value2 = operands.pop();
				String value1 = operands.pop();
				
				String subExpression = "( " + value1 + " " + operator + " " + value2 + " )";
				operands.push(subExpression);
			} else {
				operands.push(value);
			}
		}
		
		return operands.pop();
	}

}

class Ten{
    /**
     * Infix expression: The normal form of expression we see, such as 1 + 2 * 3.
     * 
     * Prefix: All operations come before the operand. Hence, A + B would be +AB. A + B * C would be +A*BC. The latter
     * happens because A + *BC, and then +A*BC. It kind of shoots the highest priority operation to right.
     * Another example is A + B*C*D + E would be +E+A+**BDC I guess.
     * 
     * Postfix: All operations come after the operand. For example, A + B would be AB+. A + B * C would be ABC*+ (postfix).
     * 
     */

     public static String infixToPostFix(String exp){
        if (exp.length() == 0 || exp == null) {
            return null;
        }

        String[] inputValues = exp.split("\\s"); // Break on \s, or white space

        Stack<String> opr = new Stack<>();
        Stack<String> ops = new Stack<>();
        for (String string : inputValues) {
            if (string.equals("*") || string.equals("+"))  ops.push(string);
            else if (string.equals("("));
            else if (string.equals(")")){
                String temp = opr.pop() + opr.pop() + ops.pop();
                opr.push(temp);
            }else{
                opr.push(string);
            }
        }

        return opr.pop();
     }

     public static void main(String[] args) {
         System.out.println(infixToPostFix("( ( 1 + 2 ) * ( 3 + 4 ) )"));
     }
}

class Eleven{
    /**
     * This is straight forward I guess. We just keep the oprands and when ever we see the an operation,
     * we do it.
     */
    public static int EvaluatePostFix(String exp) {
        if (exp.length() == 0 || exp == null) {
            throw new ArithmeticException();
        }

        String[] inputValues = exp.split("\\s"); // Break on \s, or white space

        Stack<Integer> opr = new Stack<>();
        for (String string : inputValues) {
            if (string.equals("*")){
                opr.push(opr.pop() * opr.pop());
            }
            else if (string.equals("+")) {
                opr.push(opr.pop() + opr.pop());
                
            }else{
                opr.push(Integer.parseInt(string));
            }
        }

        return opr.pop();
    }
}

class Twelve{
    /**
     * This one is easy. The question is, do we want a shallow or deep copy of the strings.
     * If we wanted a deep copy. As we know (yeah you knew :D), just assigning a string to a 
     * new variable makes a copy of it, because Strings are immutable. It's not that we actually
     * create a new copy in memory, but that if we change either of the strings, the other reference
     * is not affected, obviously!
     * 
     * In fact, any class that is immutable can be copied this way! Becuase you know, they can't be changed.
     */
    public void name() {
        String str = "a";
        String str1 = str;

        str = "b";  // Obviously str1 is not affected, because we're creating a new string reference here!

        
    }
}

class Thirteen{
    /**
     * b,c and could not occur. It's very interesting how queue keeps things in order, as opposed to stack.
     * It actually does tell you that how weird a society becomes if you don't respect the queue!
     */
}

class Fourteen{
    String[] str = new String[2];
    int N = 0;
    int first = 0;

    public void resizeArray(int size) {
        String[] d_arr = new String[size];

     //   IntStream.range(first, N).foreach(i-> d_arr[i - first] = str[i]);
        
        str = d_arr;
    }

}

class Fifteen{
    /**
     * This one was weird. Just a question: How do we get k string from the command line?
     * Maybe System.in repeats fifteen times in a loop, everytime terminates on a \n or enter?
     * 
     * By the way, I think this better be done with a stack.
     */
}

class Nineteen{
    class Node{
        Node next;
    }

    public void removeLastNode() {
        Node first = new Node();

        if (first.next == null) return;

        Node node = first;
        for (; node.next.next == null; node = node.next);
        node.next = null;
        
    }
}

class Twenty{
    /**
     * Assuming we have the first one, it's not easy. We need to iterate 17 times. Then replace the reference in 17
     * to 19.
     */
    class Node{
        Node next;
    }

    Node first;
    int N;

    public void removeElement(int k) {
        if ( k == 0){
            first = first.next;
            return;
        }

        if ( k > N - 1){
            return;
        }

        int count = 0;
        for (Node node = first; count <= k - 2 ; node = node.next){
            count++;
            if (count == k - 1){
                node = node.next.next;
            }
        };
        
        
    }
}

class TwnetyTwo{
    /**
     * Is the answer he gives correct? 
     * 
     * Suppose x->x1->t->t1. Setting t.next = x.next means x->x1->t->x1. Now x.next = t means x->t->x1. 
     * Ok, but t1 is removed!
     * 
     * If we also suppose t->t1->x->x1, it again removes whatever is after t, which is t1.
     * 
     * So there's a nuance here. It's true that we're putting t after x, but at the same time, we're removing
     * what ever there's after t!
     * 
     * I think actually trying to remove t from it's location and putting it next to x while preserving
     * the entire linked list requires knowledge of the previous node of t.
     */

     /**
      * Turns out, I was correct. Here's an implementation that actually takes care of this problem properly.
      * The scenarios are what happens if the nodes are in the beginning or end, or in the middle. We also
      * have to search for the previous node as well.
      */
    class Node { 
        int data; 
        Node next; 
        Node(int d) 
        { 
            data = d; 
            next = null; 
        } 
    } 

    class LinkedList { 
        Node head; // head of list 
    
        /* Function to swap Nodes x and y in linked list by 
        changing links */
        public void swapNodes(int x, int y) 
        { 
            // Nothing to do if x and y are same 
            if (x == y) return; 
    
            // Search for x (keep track of prevX and CurrX) 
            Node prevX = null, currX = head; 
            while (currX != null && currX.data != x) 
            { 
                prevX = currX; 
                currX = currX.next; 
            } 
    
            // Search for y (keep track of prevY and currY) 
            Node prevY = null, currY = head; 
            while (currY != null && currY.data != y) 
            { 
                prevY = currY; 
                currY = currY.next; 
            } 
    
            // If either x or y is not present, nothing to do 
            if (currX == null || currY == null) 
                return; 
    
            // If x is not head of linked list 
            if (prevX != null) 
                prevX.next = currY; 
            else //make y the new head 
                head = currY; 
    
            // If y is not head of linked list 
            if (prevY != null) 
                prevY.next = currX; 
            else // make x the new head 
                head = currX; 
    
            // Swap next pointers 
            Node temp = currX.next; 
            currX.next = currY.next; 
            currY.next = temp; 
        } 
    
        /* Function to add Node at beginning of list. */
        public void push(int new_data) 
        { 
            /* 1. alloc the Node and put the data */
            Node new_Node = new Node(new_data); 
    
            /* 2. Make next of new Node as head */
            new_Node.next = head; 
    
            /* 3. Move the head to point to new Node */
            head = new_Node; 
        } 
    
        /* This function prints contents of linked list starting 
        from the given Node */
        public void printList() 
        { 
            Node tNode = head; 
            while (tNode != null) 
            { 
                System.out.print(tNode.data+" "); 
                tNode = tNode.next; 
            } 
        } 
    }
}

class TwentyThree{
    /**
     * I agree with the statement. But the same problem as the previous exercise remains.
     */
}

class TwnetyFour{
    /**
     * If we mean just removing the next element, the solution is something like this.
     */
    public static void removeAfter(Node node) {
        if (node.next == null) return;

        node.next = node.next.next;
    }
}

class TwentySix{
    /**
     * We need to find the last node of the first, which can be done by an exhaustive search,
     * then place the nodes right after. To ensure that the first list has the correct number 
     * of nodes, we need to actually iterate over the second list! It seems kind of redundant here,
     * but the goal of the exercise is to implement this inside the linked list, and not on the outside.
     */
    public static void insertAfter(int size_list1) {
        Node first1 = new Node<>();
        Node first2 = new Node<>(); 
        

        Node node = first1;
        for (; node.next != null; node = node.next);

        node.next = first2;
        // Write a loop here that increases the index of counter
        for (; node.next != null; node = node.next){++size_list1;};
    }
}

class Thirty{
    /**
     * The reverse solution is better. So imagine we have a reverse list, and call its first node reverse. If we take a new
     * node from the old list, it should go behind the first element of reverse list (or reverse)
     * I just wish one day, I'd be able to think simply and beautifully like this!
     * 
     * Image x in the following is the first node.
     */
    static Node beautifulreverseList(Node x){
        Node first = x;
        Node reverse_first = null;
        while (first != null){
            Node second = first.next;
            first.next = reverse_first;
            reverse_first = first;
            first = second;
        }

        return reverse_first;
    }

    /**
     * As we know with recursive methods, we're supposed to have a list of size N-1, that is organized. Hence,
     * we have N->N-1->N-2->...>2, and then element one on the other side. The question is, which element do we 
     * want to return? It's the revere first element which is N. Now, what remains is making sure that the second
     * element comes before the first, and that's it. Note that the first.next = null has no effect on the 
     * nodes that are not the last node of the reverse node, because we always append an node to second, which
     * is the first of the previous step.
     */
    static Node recursiveImplementation(Node first){
        if (first == null) return null;
        if (first.next == null) return first;

        Node second = first.next;
        Node reverse = recursiveImplementation(second);
        second.next = first;
        first.next = null;
                
        return reverse;

    }
}

class ThirtyTwo{
    /**
     * Note that the cost of all operations here is 1. Also, for some reason the solution manual says
     * implements this as doubly-linked list, which I assume is not needed!
     */


    class Steque<T>{
        Node<T> first;
        Node<T> last;
        int N = 0;

        void push(T item){
            N++;
            
            Node<T> n_first = new Node<>();
            n_first.t = item;
            
            if (last == null){
                last = n_first;
            }

            first = n_first;
            if (first == null){
                n_first.next = null;
                
            } else {
                n_first.next = first;
            }

        }

        T pop(){
            if (first == null) {
                throw new RuntimeException("UnderFlow");
            }

            N--;
            T item = first.t;

            first = first.next;
            return item;
        }

        void enqueue(T item){
            Node<T> oldLast = last;
            
            last = new Node<T>();
            last.t = item;

            if (oldLast != null){
                oldLast.next = last;
            } 
            if (first == null){
                first = last;
            }

            N++;

        }

        
    }
}

class ThirtyThree_1{
    /**
     * The implementation in solution manual has loitering issues, especially suppose left = right;
     * When we set right = null for example, then left is still pointing to same memory space.
     * 
     */

     class Node<T> {
         T item;
         Node<T> prev;
         Node<T> next;
     }

    class Dequeue<T>{
        int N;

        Node<T> left;
        Node<T> right;

        boolean empty(){
            return N == 0;
        }

        int size(){
            return N;
        }

        void pushLeft(T item){
            N++;
            
            Node<T> oldLeft = left;
            oldLeft.item = item;
            left.next =oldLeft;

            if (oldLeft != null){
                oldLeft.prev = left;
            }

            if (right == null){
                right = left;
            } 
        }

        void pushRight(T item){
            N++;

            Node<T> oldRight = right;
            right.item = item;
            right.prev = oldRight;

            if (oldRight != null){
                oldRight.next = right;
            }

            if (left == null){
                left = right;
            } 
        }

        T popLeft(){
            if (empty()) { throw new RuntimeException();}
            N--;

            Node<T> oldLeft = left;
            left = left.next;

            if (left != null) left.next = null;

            if (left == right) right = null;
            else if (left.next == right){
                right.prev = null;
            }

            return oldLeft.item;
        }

        T popRight(){
            if (empty()) { throw new RuntimeException();}

            N--;
            Node<T> oldRight = right;
            right = right.prev;

            if (right != null) right.next = null;

            if (left == right) left = null;
            else if (right.prev == left){
                left.next = null;
            }

            return oldRight.item;
        }

    }
}

class ThirtyThree_2{
    /**
     * With array implementation, We want to put the first element in the middle of array, and put the elements
     * around it. When we resize, the size would be 2 * N + 1;
     * 
     * The solution manual moves to left and right,  which I don't like.
     */
    class Dequeue<T>{
        int N;
        int left;
        int right;

        T[] arr;
        Dequeue(){
            N = 3;
            arr = (T[])new Object[N];
            
            left = N / 2 + 1;
        }

        void pushLeft(T item){
            if (N + 1 == Math.ceil( arr.length / 2)) enlarge();		
            N++;
	    arr[--left] = item;

            

        }

        void pushRight(T item){
            if (N + 1 == Math.ceil( arr.length / 2)) enlarge();		
            N++;
	    arr[++right] = item;

        }

        T popLeft(){
	    T item = arr[left];
  	    arr[left] = null;
	    --N;

            if (N == Math.ceil( arr.length / 2)) shrink();
		
            return arr[left++];
        }

        T popRight(){
            return arr[right--];
        }

	/** Note: Obviously, we can merge the following two functions by asking the size of the new array as an argument. */

	/** We move every element to the center of the new array*/
        void enlarge(){
            T[] oldArr = arr;

            arr = (T[])new Object[oldArr.length * 2 + 1];

            int middle = (int)Math.ceil((oldArr.length * 2 + 1) / 2);
            int middle_old =(int) Math.ceil(oldArr.length / 2);
            for (int i = left; i <= right ; i++) {
                arr[ i + middle - middle_old ] = oldArr[i];
            }

            left = left + middle - middle_old;
            right = right + middle - middle_old;
        }

	/** We move every element to the center of the new array*/
        void shrink(){
            T[] oldArr = arr;

            arr = (T[])new Object[(int)Math.ceil(oldArr.length/2)];

            int middle = (int)Math.ceil(oldArr.length)
            int middle_old = (int)Math.ceil(Math.ceil(Math.ceil(oldArr.length/2) /2));
            for (int i = left; i <= right ; i++) {
                arr[ i + middle - middle_old ] = oldArr[i];
            }

            left = left + middle - middle_old;
            right = right + middle - middle_old;
        }

    }
    
}

class ThirtyFour{
	/** There are several solutions here. One is to implement bag as a linked list, then create an array
	* the same size as the bag, and then randomly put it there, assuming if an array position is null then
	* we can place in it.*/
	class RandomBag<T>{
		Node<T> first;
		int N;
		Node<T> last;

		void add(T item){
		   N++;
		   Node<T> oldLast = last;
	           last = new Node();
		    last.t = item;
		   oldLast.next = last; 	
		   
		   if (first == null) first = last;	
		} 

		class RandomIterator<T> implements Iterator<T>{
			RandomIterator(Node<T> first){
				T[] arr = (T[])new Object[N];

				for (Node<T> node = first; node != null; node = node.next){
					int random_index = 0;
					// Generate random number, checking arr[] at that position is null, else repeat.
                    arr[random_index] = node.t;
				}	
			}

            @Override
            public boolean hasNext() {
                // TODO Auto-generated method stub
                return false;
            }

            @Override
            public T next() {
                // TODO Auto-generated method stub
                return null;
            }
		}
	}
}


class ThirtyFive{
	/** I think a simpler solution for randomness would be to choose an integer between 1 and N, iterate over
	  the list, and then return that element. This I think is a lot better than the suggested array approach.
	*/
	class RandomQueue<T>{
		Node<T> first;

		T sample(){

		    int index = 0;//Math.Rand(1);
		    
		    int ctr = 0;	
		    Node<T> node = first;
		    for (; node != null && ++ctr != index ; node = node.next);
		    return node.try {
                
            } catch (Exception e) {
                //TODO: handle exception
            };
		}
	}

	
}

class ThirtySeven{
	/**
	* The circular behavior that we can simulate with the queues is quite interesting. This is because 0->1->2->3
	* could be imagined as if in a circle!
	* What happens if for example M = 4? Huh, we still continue counting, 
	* and go around until we find the next person to eliminate.
	*/

	static void main(String[] args){
		Queue<Integer> queue;
		int N = 7;
		int M = 2;

		for (int i = 0; i < N; i++){
			queue.add(i);
		}

		while (queue.size() != 1){
			for (int j = 0; j <= M - 2; j++)
			{
				queue.add(queue.element());
			}
		}
	}

	
}

class ThirtyEight{
	/**
	 This is pretty straight forward. The only point is that if k > size/2, if we implement the list as double-linked array,
	 we can start from the back.
	*/
}

class ThirtyNine{
	/**
	   The issue here is that when the consumer consumes data, then we start to have empty positions at the beginning of the queuqe.
	   Now suppose we produce some data. What would happen then? Well. One solution would be to shift all parameters to left.
	   If we absolutely don't want any data to be lost, the solution would be to have a separate queue, which would hold the 
	   produced data. This data would come in, and will be set in the array only once the array is fully empty I guess. Again,
	   the beautiful point here is that to add to the array, we use the produce method, not writing a separate method LoL!

	   Yes. The cicular buffer can be written in such a way that data is overwritten in the ring.
	*/
	class RingBuffer<Item>{
    private Item[] ringBuffer;
    private int size;
    private int first;
    private int last;

    private Queue<Item> producerAuxBuffer;
    private int dataCountToBeConsumed;

    public RingBuffer(int capacity) {
        ringBuffer = (Item[]) new Object[capacity];
        size = 0;
        first = -1;
        last = -1;

        producerAuxBuffer = new Queue<>();
        dataCountToBeConsumed = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public void produce(Item item) {

        if (dataCountToBeConsumed > 0) {
            //There is data to be consumed
            consumeData(item);
            dataCountToBeConsumed--;
        } else {
            if (isEmpty()) {
                ringBuffer[size] = item;
                first = 0;
                last = 0;
                size++;
            } else {
                if (size < ringBuffer.length) {
                    if (last == ringBuffer.length - 1) {
                        last = 0; //wrap around
                    } else {
                        last++;
                    }
                    ringBuffer[last] = item;
                    size++;
                } else {
                    //RingBuffer is full - add to auxiliary Producer Buffer
                    producerAuxBuffer.add(item);
                }
            }
        }
    }

    private void consumeData(Item item) {
        //Consumer consumes the item
        
    }

    public Item consume() {
        if (isEmpty()) {
            dataCountToBeConsumed++;
            return null;
        }

        Item item = ringBuffer[first];
        ringBuffer[first] = null; //avoid loitering

        if (first == ringBuffer.length - 1) {
            first = 0; //wrap around
        } else {
            first++;
        }

        size--;

        if (!producerAuxBuffer.isEmpty()) {
            produce(producerAuxBuffer.element());
        }

        return item;
    }

    @Override
    public Iterator<Item> iterator() {
        return new RingBufferIterator();
    }

    private class RingBufferIterator implements Iterator<Item> {

        private int current = first;
        private int count = 0;

        @Override
        public boolean hasNext() {
            return count < size;
        }

        @Override
        public Item next() {
            Item item = ringBuffer[current];

            if (current == ringBuffer.length - 1) {
                current = 0; //Wrap around
            } else {
                current++;
            }

            count++;
            return item;
        }

    }
}

class Forty{
    /**
     * Well, the search is of order n. One interesting solution here would be to have the chars in a set,
     * so that we can save time searching for them.
     */
    class FrontStrategy{
        class Node{
            Node next;
            char c;
        }
        Node first;
        Node last;

        Set<Character> set = new TreeSet<>();

        void insert(char c){
            if (set.contains(c)){
                replace(c);
            }
            
            set.add(c);

            Node oldFirst = first;
            first = new Node();
            first.c = c;

            if (oldFirst != null){
                first.next = oldFirst;
            }
        }

        void replace(char c){
            Node previous = null;
            Node current = first;
            for (; current.next != null; ){
                if (current.c == c){
                    break;
                }
                previous = current;
                current = current.next;
            }

            /** We can also write the loop using one variable, but then we have to check if next is not null.
             * To write it with one variable, we need to check if the next char is the one we're looking for.
             * for (Node curr = first; curr.next != null; curr = curr.next ){
             *   if (curr.next.c == c){
             *       break;
             *   }
             * }
             */
            
            if (previous == current){
                return;
            }

            if (previous != null){
                previous.next = current.next;
            }else{
                current = current.next;
            }


        }

    }
}
}

class FortyOne{
    /**
     * I think if we're sure that there are no duplicates in the queue, we can actually take the first element
     * after dequeue and queue it, and then repeat this process until we get arrivate at that first element. So in
     * fact a peek would suffice, rather than a delete.
     */
}

class FortyTwo{
    /**
     * With this one, I think we can implement recursion
     */
    Queue fileQueue;
    private void listFiles(File file, int depth) {
        if (!file.exists()) {
            return;
        }

        //Add directory
        addFileToQueue(file, depth);

        File[] fileList = file.listFiles();

        if (fileList != null) {
            for(File fileItem : fileList) {

                if (fileItem.isFile()) {
                    addFileToQueue(fileItem, depth);
                } else if (fileItem.isDirectory()) {
                    listFiles(fileItem, depth+1);
                }
            }
        }
    }

    private void addFileToQueue(File file, int depth) {
        StringBuilder stringBuilder = new StringBuilder();

        for(int i = 0; i < depth; i++) {
            stringBuilder.append("  ");
        }

        stringBuilder.append(file.getName());

        fileQueue.add(stringBuilder.toString());
    }
}

class FortyFour{
    /**
     * One solution here is to use a doubly linked list, to be able to move back from the front.
     * The other would be to use two stacks. When we move to the left, one stack pops, and puts in 
     * the other stack (reverse stack). Now we can put the data in the original stack. However, if we move to right,
     * we start poping from the other stack, and put chars here.
     */
    class Buffer{
        Stack<Character> stack = new Stack<>();
        Stack<Character> reverse = new Stack<>();

        void moveLeft(int k){
            for (int i = 0; i < Math.max(k, stack.size()); i++){
                reverse.add(stack.pop());
            }
        }

        void moveRight(int k){
            for (int i = 0; i < Math.min(k, reverse.size()); i++){
                stack.add(reverse.pop());
            }

            for (int i = 0; i < k - reverse.size(); i++){
                stack.add('\0');
            }
        }


    }
}

class FortyFive{
    /**
     * Obviously, if the number of pops and integers are not equal, then the given permutation is incorrect.
     */
    public boolean doesStackUnderFlow(String[] str){
        int item_count = 0;

        for (String string : str) {
            if (string.equals("-")){
                item_count--;
            } else{
                item_count++;
            }

            if (item_count < 0){
                return false;
            }
            
        }

        return true;
    }
     /**
     * 
     * 
     * For the second part:
     * In a permutation, if we have x, then the next element in the permutation must be either x-1, or it must  y > x,
     * (which would make y the greatest element of the stack)
     */
    static boolean isPermutationValid(String[] str){
        int max = Integer.parseInt(str[0]);

        for (int i = 1; i < str.length; i++){
            int val = Integer.parseInt(str[i]);
            if (max - 1 == val){}
            else if (val > max){
                max = val;
            } else{
                return false;
            }

        }

        return true;

    }

    public static void main(String[] args) {
        System.out.println(isPermutationValid("0 4 6 5 3 8 1 7 2 9".split(" ")));
    }
}

class FortySix{
    /**
     * If permutation has no forbidden triple -> It's generated by stack push and pop
     * If permutation is generated by stack push and pop -> it has no forbidden tripple.
     * 
     * If a permutation has no FT, then for each triplet x .. y .. z in the permutation, we can define a scenario
     * of how they're put in the stack. Hence, this side holds true.
     * 
     * If the permutation is generated by the stack, it cannot have FT, because suppose it does. It would imply that b is 
     * popped after a has been popped, which is impossible.
     */
}

class FortySeven{
    /** I don't understand the question really */
}