/**
 * So we understood that even though the memory size of the structure is 5, size of says it's 6.
 * 
 * To understand why this is the case, we need to introduce the memory alignment concept. The CPU always does all the 
 * computations. Besides that, it needs to load values from memory before being able to compute anything and needs to 
 * store the results back again in the memory after a computation. Computation is super-fast inside the CPU, but the
 * memory access is very slow in comparison. It is important to know how the CPU interacts with the memory because then 
 * we can use the knowledge to boost a program or debug an issue.
 * 
 * The CPU usually reads a specific number of bytes in each memory access. This number of bytes is usually called a word. 
 * So, the memory is split into words and a word is an atomic unit used by the CPU to read from and write to the memory. 
 * The actual number of bytes in a word is an architecture-dependent factor. For example, in most 64-bit machines, the 
 * word size is 32 bits or 4 bytes. Regarding the memory alignment, we say that a variable is aligned in the memory if its 
 * starting byte is at the beginning of a word. This way, the CPU can load its value in an optimized number of memory 
 * accesses. (ME: This is also different from caching!)
 * 
 * Regarding the previous example, the first 3 fields, first, second, and third, are 1 byte each, and they reside in the 
 * first word of the structure's layout, and they all can be read by just one memory access. About the fourth field, 
 * fourth occupies 2 bytes. If we forget about the memory alignment, its first byte will be the last byte of the first 
 * word, which makes it unaligned. If this was the case, the CPU would be required to make two memory accesses together 
 * with shifting some bits in order to retrieve the value of the field. Thus, the compiler pads an extra byte after the
 * first three bytes for us to make the access unpainful for CPU, to stop it from reading the fourth byte, then shifting
 * it, and then adding it. The zero byte has been added in order to complete the current word and let the fourth field 
 * start in the next word. Here, we say that the first word is padded by one zero byte. The compiler uses the padding 
 * technique to align values in the memory. Padding is the extra bytes added to match the alignment. (ME: So notice that
 * this is done by compiler automatically based on the knowledge it has of the CPU. We know nothing about this as such.)
 * 
 * It is possible to turn off the alignment. In C terminology, we use a more specific term for aligned structures. We say 
 * that the structure is not packed. Packed structures are not aligned and using them may lead to binary incompatibilities 
 * and performance degradation. You can easily define a structure that is packed. We will do it next.
 * 
 * ME: As such, it's not a good idea to use not multiples of fours in this structure. For example, if we have a char and
 * and an int, would the size be 8? Yessum! 
 * 
 * ME: Note that as such, we still need to care about all these 8 bits. Meaning if we're copying memory, we should copy
 * these too, because afterall, now the memory is 8 bits as dictated by the compiler. However, if we're printing it
 * for example, we should not print those three added words!
 * 
 * Me: It's interesting to me that the same story does not happen to arrays. Possibly because arrays are essentially
 * multiples of four? I guess.
 */

#include <stdio.h>

struct s_t{
	char t;
	int i;
};

int main(){
	printf("%i\n", sizeof(struct s_t));
}