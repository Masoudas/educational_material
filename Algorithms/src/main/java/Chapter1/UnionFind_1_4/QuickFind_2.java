package Chapter1.UnionFind_1_4;

import java.util.Arrays;
import java.util.stream.IntStream;

/**
 * Normally, I would write a matrix representing the connections like a graph. The problem with that is that
 * finding the connections with that is not trivial.
 * 
 * Another way which was very cool is this. Define an array. At first each site is linked to itself. Hence, 
 * the value of each element, which would indicate its component name, would be its site name (id[p] = p)
 * When a connection is added however, set the component name of the two sites equal to one of them, for example p.
 * The issue however is that there may be other sites connected to q. Hence, we need to set all of their component
 * names to p as well. 
 * 
 * Now, the question of whether two sites are connected simply becomes, do they have the same component identifier
 * (id[p] == id[q]). Moreover, Note that each time two unconnected sites become connected, we decrease the number of
 * components.
 * 
 * The important point in the union method is that if two sites are already connected, nothing should be done.
 * Note that the assignment of the ID is completely arbitrary (could have been q).
 */
class QuickFind implements UI{
    int[] id;
    int component;
    QuickFind(int N){
        id = new int[N];

        
        IntStream.range(0, N).foreach(i -> id[i] = i);
        component = N;
    }

    @Override
    public void union(int p, int q) {
        // If you're wondering why we're not directly using id[p] and id[q], see exercise 8. Boo Yah!
        int id_p = find(p);
        int id_q = find(q);

        if (id_p == id_q)return;

        for (int i : id) {
            if (find(i) == id_q) id[i] = id_p;
        }

        component--;
    }

    @Override
    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    @Override
    public int find(int p) {
        return id[p];
    }

    @Override
    public int count() {
        return component;
    }
    
}

/**
 * Now the question is, what is the cost of the union method?
 * In the worst case scenraio, we have N-1 sites connected, and then next one is to be connected. In this case,
 * we need to access the each site one to read it, and possibly once to write in it. If we don't need to write in it,
 * we need N-1 reads, plus reading last element, plus writing in it, plus two acces for the connectivitiy check.
 * Hence, we need N - 1 + 1 + 1 + 2 = N + 3. If however we need to write in the other N-1 elements, we need 2N - 2 + 3 = 2N + 1 access
 * to the array.
 * 
 * Now suppose, we define connections between all the N - 1 components. Hence, at best we need to perform (N+3)(N-1) operatios to
 * declare these connectivities. Hence, we have a quadratic problem at our hands, when we're trying to define the connections.
 * For very large networks, this is a very big problem. Hence, even though this solution is ingenius, we still need to find better ones.
 * 
 */