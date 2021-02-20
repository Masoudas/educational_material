package Chapter1.UnionFind_1_4;

/**
 * As we already know, and equivalence relation is where for each pair (p,q):
 * Symmetry: p~p
 * reflexitivity: if q ~ p, then p ~ q
 * Transitivity: p~q and q~w, then p~w.
 * 
 * Moreover, we know that can form equivalence classes, where a particular set of elements are equivalent to one
 * element. A famous example of this is the set of integers, together with a module operation (With module 3 for example,
 * equivalence classes are 0, 1 and 2).
 * 
 * Now the question is, how can we determine whether two elements are connected? For example, 1~3 and then 3~4. Then how 
 * can we know declare that 1~4. 
 * 
 * 
 * To answer this question. We start with the simple case of knowing we have N pairs. We call each pair 0, ..., N-1 a 
 * site, and a connection such as 1~2 a component. We define the following API (called Union Finder or UF):
 * 
 * In what follows, we asses a couple of ways of implementing the following API.
 * 
 * WE SHOULD NOT FORGET that if transitivity were not present, our only solution would have been to keep the
 * connections one by one. Because in this scheme, if 1->2 and 2->3, then 1->3. If we didn't want this (and only
 * wanted those exact relations), we should have kept them as pairs.
 */
interface UI{
    // Constructor gets N.
    void union(int p, int q); // Declares that sites p and q are a component.
    boolean connected(int p, int q);    // Determines whethe p and q are a component.
    int find(int p);    // Determines the component identifier.
    int count();    // Returns the number of components 
}