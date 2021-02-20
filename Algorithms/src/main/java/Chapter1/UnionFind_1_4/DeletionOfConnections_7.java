package Chapter1.UnionFind_1_4;

/**
 * What do we mean by deletion of a connections in a union find algorithm? Obviously,
 * one solution is to delete the two nodes, so that they wouldn't be connected to one another, and all the other
 * nodes. However, what if we said even though p is not connected to q, it is connected to its older 
 * nodes? We can't say this, because it would collide with definition of transitivity. Because if p~a and q~a,
 * then p~q. So, the only suggestion is to delete the two nodes, i.e, making them parent nodes.
 */