/**
* As an example, consider the String class template:
* template<typename C> class String { // ... };
* 
* In particular, we ask ourselves, what does it take to be a character in such a character string class?
* An experienced designer will have a small number of likely answers to that question and start the design based 
* on those. However, let us consider how we might answer it from first principles. We proceed through three stages
* of analysis:
* 
* [1]	First, we look at our (initial) implementation and determine which properties (operations, functions, 
*		member types, etc.) it uses from its parameter types (and the meaning of those operations). The resulting 
*		list is the minimal requirements for that particular template implementation.
* [2]	Next, we look at plausible alternative template implementations and list their requirements on their 
*		template arguments. Doing so, we may decide that we should place more or stricter requirements on the 
*		template arguments to allow for alternative implementations. Alternatively, we might decide to prefer an 
*		implementation that makes fewer and/or simpler requirements.
* [3]	Finally, we look at the resulting list (or lists) of required properties and compare it to lists of 
*		requirements (concepts) that we have used for other templates. We try to find simple, preferably common, 
*		concepts that can express what would otherwise be many long lists of requirements. The aim here is to make 
*		our design benefit from general work on classification. The resulting concepts are easier to give 
*		meaningful names and easier to remember. They should also maximize the degree of interoperability of 
*		templates and types by limiting variations in concepts to what is essential.
* 
* The first two steps are – for fundamental reasons – very similar to the way we generalize ("lift") concrete 
* algorithms into generic algorithms. The last step counteracts the temptation to provide each algorithm with a 
* set of argument requirements that exactly match its implementation. Such requirement lists are overspecialized 
* and not stable: each change to the implementation would imply changes to the requirements documented as part of 
* the algorithm’s interface.
* 
* What are the requirements on C. One can think of the following:
* 1- It has == and != operators
* 2- It is copiable by copy initialization and assignment
* 3- We can create an array out of it (which we know from experience implies that it's default constructible)
* 4- It can be streamed (as << or >>)
* 5- It is destructible
* 6- The address of chars can be extracted.
* 
* Requirements 5 and 6 are deemed fundamental for most type (and the big guy says they're almost always clever
* artifacts.) Requirement 2 is not true for some types (like unique_ptr for example). The ability to invoke a copy 
* operation goes together with the semantic requirement that a copy really is a copy of the original, that is, that 
* – except for taking the address – the two copies behave identically. Therefore, the ability to copy usually 
* (as for our String) goes together with the requirement to provide == with the usual semantics.
* 
* By requiring assignment, we imply that a const type cannot be used as a template argument. For example, 
* String<const char> is not guaranteed to work. That’s fine in this case, as in most cases. Having assignment means 
* that an algorithm can use temporary variables of its argument type, create containers of objects of an argument 
* type, etc. It does not imply that we cannot use const to specify interfaces. For example, int the operator== below,
* the operator signals that nothing is being copied by accepting const arguments. However, String in and of itself
* is copiable.
* 
* Should we require a move for an element type C? After all, we provide move operations for String<C>. We could, 
* but it’s not essential: what we do with a C can be handled by copying, and if some copy is implicitly turned into 
* a move (e.g., when we returned a C), so much the better. In particular, potentially important examples, such as 
* String<String<char>>, will work fine (correctly and efficiently) without adding move operations to the requirements.
* 
* the last requirement (that we can read and write Cs using >> and <<) seems excessive. Do we really read and write 
* every kind of string? Maybe it would be better to say that if we read and write a String<X>, then X must provide 
* >> and <<? That is, instead of placing a requirement on C for the whole String, we require it (only) for Strings 
* that we actually read and write.
* 
* This is an important and fundamental design choice: we can place a requirement on class template arguments (so 
* that they apply to all class members) or just to template arguments on individual class function members. The 
* latter is more flexible, but also more verbose (we have to express the requirement for each function that needs 
* it) and harder for a programmer to remember.
* 
* Finally, we can also impose the following two constraints on the type:
* [1] Types are orderable with <.
* [2] Conversion to integer.
* 
* After comping up with such constraint, we can think of which types satisfy these conditions. Regular types are
* an important example, because:
* -	You can copy (using assignment or initialization) with the proper copy semantics
* - You can default construct
* - Doesn’t have problems with various minor technical requirements (such as taking the address of a variable)
* - you can compare for equality (using == and !=)
* 
* That seems an excellent choice for our String template arguments. I considered leaving out the equality 
* comparisons but decided that copying without equality is rarely useful. Typically, Regular is the safe bet, and 
* thinking about the meaning of == can help avoid errors in the definition of copying. All the built-in types are 
* regular.
* 
* But does it make sense to leave out ordering (<) for String? Consider how we use strings. The desired use of a 
* template (such as String) should determine its requirements on its arguments. We do compare strings extensively, 
* and in addition we use comparisons indirectly when we sort sequences of strings, we put strings into sets, etc. 
* Also, the standard-library string does provide <. It is usually a good idea to look to the standard for 
* inspiration. So, we require not just Regular for our String, but also ordering. That’s the concept Ordered.
*/

template <typename T>
struct String{};
template<typename T>
bool operator==(const String<T>& s1, const String<T>& s2)
{
	if (s1.size() != s2.size()) return false;
	for (auto i = 0; i != s1.size(); ++i)
		if (s1[i] != s2[i]) return false;
	return true;
}