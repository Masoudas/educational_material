/**
* We maintain that we require at most 1 + logN for insertion of a new node. Why? Because the node is put at
* depth logN. But then we'd need logN comparisons. I don't know why we say logN + 1.
* 
* For deletion, we require comparison with both childern, hence we need 2logN comparisons.
* 
* 
* Note that we may create a tree with d children at each level, which would have a depth of logd(N). The 
* trade-off however is that sink and swim now involves several nodes instead of two, which if not implemented
* properly can degrade performance.
*/