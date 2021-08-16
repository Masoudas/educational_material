/**
 * To circumvent the addition of the padding bytes, one can use pack attribute of structures, which may lead to performance
 * degredation. 
 * 
 * As such, the printed size would be 5 bytes.
 */

#include <stdio.h>
struct __attribute__((__packed__)) sample_t {
  char first;
  char second;
  char third;
  short fourth;
} ;

void print_size(struct sample_t* var) {
  // ...
}
void print_bytes(struct sample_t* var) {
  // ...
}
int main(int argc, char** argv) {
  // ...
}