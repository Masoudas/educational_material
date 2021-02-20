package Chapter1.UnionFind_1_4;

/**
 * One problem that makes the quick union impractical is the fact that we need to find the root, which
 * if the branch is long, would take long. But imagine this. If we a have a branch 1->2 and a node 3,
 * if instead of saying 3->1->2, we say 1->3 and 1->2, then each node would be linked to its parent by
 * one link. Of course we still can have long branches, but still, the cost will come down.
 * 
 * So to remedy this, we keep the size of each tree (how many nodes it has). When we're about to connect
 * to parents, we connect the smaller tree to the larger tree (making the parent of larger tree, the parent of the
 * smaller tree).
 * 
 * Question I: Why not keep track of tree depth rather than size?
 * 
 * 
 * Question I: Prove that the maximum depth of any node in a tree of size N is logN? Note that we say
 * any node. However, if we prove this for the parent node, we're fine (because it's the deepest).
 * It's pointless to answer this question using normal induction (from n node to n+1 node).
 * Because suppose we use induction. If we add one node to a tree, it's size increases by one and logn remains.
 * So, we need to show that a combination of two trees results in the proposition. Mor
 * We need the strong induction argument. So suppose a tree has K and another has M nodes (K>=M), where K + M = N.
 * Then adding these two together obviously increases the depth of M by one. However. log(M) + 1 <= log(M + M) <= log(M + K) <= logN.
 * 
 * 
 * Hence in this schema, the cost of find is only logN.
 * 
 * 
 * To implement this schema, we define an array containing the depth of each node. Everytime a node is 
 * added, we add one to its depth.
 */
class WeightedQuickUnion implements UI{
    int[] sz;
    int[] id;
    int component;

    WeightedQuickUnion(int N){
        sz = new int[N];
        id = new int[N];
        component = N;
    }

    public boolean connected(int p , int q){
        return find(p) == find(q);
    }

    public void union(int p, int q){
        int id_p = find(p);
        int id_q = find(q);

        if (id_p == id_q) return;

        if (sz[id_p] > sz[id_q]){
            id[id_q] = id_p;
            sz[id_p] += sz[id_p] ;
        }else{
            id[id_p] = id_q;
            sz[id_q] += sz[id_p];
        }

        component--;
    }

    public int find(int p){
        while (id[p] != p) p = id[p];
        return p;
    }

    public int count(){
        return component;
    }
}
