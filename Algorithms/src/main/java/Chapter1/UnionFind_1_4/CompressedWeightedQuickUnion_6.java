package Chapter1.UnionFind_1_4;

/**
 * One interesting variation that we can do to WeightedQuickUnion is that we add another loop
 * to the find method, so that everytime we try and find the parent, we just set the parent id
 * of all nodes visited to the parent directly. That way, each node will be directly below the
 * parent (e.g, 1->2 1->3->4 becomes 1->2 1->3 1->4). But this variation has no practical improvement
 * over WeightedQuickUnion, studies have found.
 * 
 * The reason why this algorithm may not always get the best result is this. Imagine we set the id of all
 * nodes with a particular id to 1, then it will have the same performance as quick find.
 * 
 * Now imagine only setting the id of the nodes we're visiting. In that case, we can imagine scenarios where
 * the trees don't change, namely where the connections are made solely using the id of the self-referencing node.
 * For example 1->2 3->4 and then we say 1 is connected to three. Then all of a sudden, we have 
 * a tree with height 2! So we see that it's possible to have larger trees.
 * 
 */