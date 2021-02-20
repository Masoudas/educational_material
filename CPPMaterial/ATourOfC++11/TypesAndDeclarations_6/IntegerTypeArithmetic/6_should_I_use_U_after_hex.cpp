/**
* So, this interesting question came to me a while ago, while I wanted to assign a hexadecimal to a size_t, while
* calculating the hash of a class.
* 
* Question: Which of the following is correct?
* size_t t = 0xF0000000; 
* size_t t = 0xF0000000U;
* 
* The answer is both. The point is that when we define a number in hex, binary or octal base, the compiler finds
* a type that fits the exact given bit layout. So for example the first number is a big integer value that is at
* least 2^31 but less than 2^32, and the complier discards int and chooses unsigned int for that. The second one is 
* equivalent to the first, with the minor difference being that the compiler starts with unsigned int.
* 
* Also, the standard explicitly says that "Here are no negative integer literals. Expressions such as -1 apply the 
* unary minus operator to the value represented by the literal, which may involve implicit type conversions."
* 
* In conclusion, the above simple explaination of the rule is characterized by the following standard table:
*		Suffix				Decimal bases				Binary, octal, or hexadecimal bases 
* (no suffix):				- int								- int
*							- long int							- unsigned int
*							- long long int						- long int
*																- unsigned long int
*																- long long int
*																- unsigned long long int
* 
*	u or U:					- unsigned int						- unsigned int
*							- unsigned long int					- unsigned long int
*							- unsigned long long int			- unsigned long long int
*
*	l or L:					- long int							- long int
*							- long long int						- unsigned long int
*																- long long int
*																- unsigned long long int 
* 
*	l/l and u/U				- unsigned long it					- unsigned long it
*							- unsigned long long int			- unsigned long long int
* 
*	ll/ LL					- long long int						- long long int
*							- unsigned long long int			- unsigned long long int
* 
*	z or Z					- the signed version of std::size_t - the signed version of std::size_t
*																- std::size_t
*   
*   z/Z and u/u				- std::size_t						- std::size_t
* 
*/




