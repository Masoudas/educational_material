/**
* If we want to, we can place constraints checks almost anywhere. For example, to guarantee that a particular type 
* is checked against a particular concept, we could place constraints checks in a namespace scope (e.g., the global 
* scope). For example:
 
static_assert(Ordered<std::string>,"std::string is not Ordered"); 
static_assert(Ordered<String<char>>,"String<char> is not Ordered"); 

* 
*/