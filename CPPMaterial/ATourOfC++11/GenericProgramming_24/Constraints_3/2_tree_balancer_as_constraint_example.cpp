/**
* An example of a constraint is a tree balancer algorithm. A balancer for example might provide the following 
* method signatures:
struct Red_black_balance {
// ...
template<typename Node> static void add_fixup(Node* x);
template<typename Node> static void touch(Node* x);
template<typename Node> static void detach(Node* x);
};
* The big guy says "Obviously, we’d like to say what’s required of node_base’s arguments, but a balancer is not 
* meant to be a widely used and easily understood interface; it’s meant to be used only as a detail of a particular 
* implementation of balanced trees. This idea of a balancer (I hesitate to use the word ‘‘concept’’) is unlikely to 
* be used elsewhere or even to survive a major rewrite of the balanced tree implementation unchanged. It would be 
* hard to pin down the exact semantics of a balancer. For starters, the semantics of Balancer would critically 
* depend on the semantics of Node. In those aspects, a Balancer differs from a proper concept, such as 
* Random_access_iterator. We can, howev er, still use the minimal specification of a balancer, ‘‘provides those 
* three functions on nodes,’’ as a constraint on arguments to a node_base.
* 
* Moreover, "Note the way 'semantics' keep cropping up in the discussion of concepts. I find that 'Can I write out 
* a semiformal semantics?’’ to be the question that is most helpful when it comes to deciding whether something is 
* a concept or simply an ad hoc collection of constraints on a type (or set of types). If I can write out a 
* meaningful semantic specification, I have a concept. If not, what I have is a constraint that may be useful but 
* shouldn’t be expected to be stable or widely useful"
*/