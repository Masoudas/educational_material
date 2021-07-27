/**
 * The memory structure of a structure can adversly affect the performance.
 * 
 * Note: Recall that before declaring or using a structure, the structure keyword has to be put. As such, it's best
 * to define a structure together with a typedef:

typedef struct{
	...
} my_t;

 * Now, going back to the example below, it's interesting to note that the size of this structure would be 6, and not
 * 5 (3 + 2). Note however that when we iterate over it byte by byte, we print exactly five bytes and then we're done!
 * 
 * Why this is the case is discussed next.
 */

#include <stdio.h>
struct sample_t {
    char first;
    char second;
    char third;
    short fourth;
};

void print_size(struct sample_t* var) {
    printf("Size: %lu bytes\n", sizeof(*var));
}

void print_bytes(struct sample_t* var) {
    unsigned char* ptr = (unsigned char*)var;
    for (int i = 0; i < sizeof(*var); i++, ptr++) {
      printf("%d ", (unsigned int)*ptr);
    }
    printf("\n");
}
int main(int argc, char** argv) {
    struct sample_t var;
    var.first = 'A';
    var.second = 'B';
    var.third = 'C';
    var.fourth = 765;
    print_size(&var);
    print_bytes(&var);
    return 0;
}