/**
* Interestingly, there has been quite some debate on whether Regular should require < or not. It seems that most 
* types related to numbers have a natural order. For example, characters are encoded in bit patterns that can be 
* interpreted as integers, and any sequence of values can be lexicographically ordered. However, many types do not 
* have a natural order (e.g., complex numbers and images) even though we could define one. Other types have several 
* natural orderings, but no unique best ordering (e.g., records may be ordered by name or by address). Finally, 
* some (reasonable) types simply don’t hav e an order
* 
* In conclusion, it appears that regular types can be both ordered types and not, and if so, there maybe several
* natural orders applicable to them. Hence, the two are separable.
* 
* Finally, some (reasonable) types simply don’t have an order. For example, consider the enum defined below. We
* know that rock < paper, paper < scissor, scissor < rock (Me: However, an enum is not an ordered type, as discussed
* in chapter 8, section 4, even though a natural comparison exists for it). However, our String is not supposed to 
* take an arbitrary type as its character type; it is supposed to take a type that supports string operations (such  
* as comparisons, sorting, and I/O), so I decided to require ordering. (Me: I don't get it! An enum is comparable 
* after all with another enum, so there's an order afterall, however he implies that it's not!).
*/

#include <iostream>

enum class rsp { rock, scissors, paper };

/**
* Recall that enums are comparable to each other, mostly because they're equaly comparable to one another as well.
*/
void recall_that_can_compare_enums_directly() {
	bool ist = rsp::rock < rsp::scissors;
	std::cout << ist;
}

//int main() {
//	recall_that_can_compare_enums_directly();
//}


