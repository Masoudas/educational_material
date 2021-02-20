package Chapter1.UnionFind_1_4;

import java.util.stream.IntStream;

/**
 * One thing that we did in the previous algorithm which was unnecessay, was that we gave all the 
 * components the same name, and because of this, we had to iterate all over the ids. Hence, our search
 * is linear.
 * 
 * Here's how we can change it. We know that an equivalence can always be associated to one element (for
 * example, in module 3, 0 is equivalent to 3, 6, ...). Now, let's assume that we have such element, which
 * we call a parent node. The goal is to find this parent node for two sites, and then make only one of them
 * the representative (thus making the other child of it)
 *
 *  
 * The algorithm is called quick union, because making connections is very quick here.
 * 
 * So, we refer to the id entry of each site as link. We refer to sites as nodes.
 * 
 * In the find method, we follow each site to another site, until we reach a root, which is an element linked to itself.
 * 
 * We can prove by induction that every node has a root. It's true for the first step. Then suppose we're at step (N-1), and
 * evey node has a root, it will then be true with the next union as well, as summarized above. Note that in this scheme,
 * all nodes connected nodes would have the same id as well.
 * 
 * Question is: what is the cost of union? ? ?
 */

class QuickUnion implements UI{
    int[] id;
    int component;

    QuickUnion(int N){
        IntStream.range(0, N).foreach(i -> id[i] = i);
        component = N;
    }

    @Override
    public void union(int p, int q) {
        int id_p = find(p);
        int id_q = find(q);

        if (id_p == id_q) return;

        id[id_p] = id_q;
        component--;
    }

    @Override
    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    @Override
    public int find(int p) {
        while(id[p] != p) p = id[p];

        return p;
    }

    @Override
    public int count() {
        return component--;
    }
    
}

