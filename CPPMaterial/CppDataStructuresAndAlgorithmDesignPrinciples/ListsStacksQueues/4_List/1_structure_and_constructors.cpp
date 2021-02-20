/**
* As opposed to forward_list, list provides a way of getting the size, getting the last element, and traversing
* backward.
* 
* A list is a bidirectional linked list. Each element has next and previous. Construction for most cases is the
* same as forward_list, so we're not going to discuss them.
* 
* Note however that many of the methods, including push_front, push_back, erase, emplace, etc are slightly
* more expensive than a forward_list, because we actually need to reassign the last node in this case too.
* 
* In general, unless you very restrict memory and performance criteria in place, use list instead of forward_list.
*/