package Chapter1.BagsQueuesAndStacks_1_3;

import java.util.TreeSet;

class Node{
    Node next;
}

public class LoopDetectionProblemsInLinkedLists_8 {
    /**
     * How does one detect if there's a loop in a linked list?
     * I think the simplest solution is that if there's no null in the linked list, then
     * we have a loop. But the question is that how can we check against not having a null?!
     * We can't! Which is why for example we have to use a HashMap, or a set to check if the
     * node has already been traversed.
     * 
     * Also, if we know the size of the linked list, we may write a loop an go through it and if we
     * see that there's no null at the i-th element, then there's a loop. This solution saves us
     * some space, but has to go through the entire list.
     */
    public void loopDetectorUsingSet() {
        Node first = new Node();

        boolean hasLoop = false;
        TreeSet<Node> unique_nodes = new TreeSet<>();
        for (Node node = first; node.next != null && !hasLoop; node = node.next){
            if (unique_nodes.contains(node)){
                hasLoop = true;
            }

            unique_nodes.add(node);
        }
        
    }

    public boolean detectKnowingSize(int total_nodes) {
        Node first = new Node();
        int node_ctr = 1;

        Node current = first;
        for ( ; ++node_ctr != total_nodes;){
            current = current.next;
        }
        
        return current.next == null;

    }

    
}
