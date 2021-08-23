/**
 * To define a private behavior, an option is to only use the method in the source file. As such, the method would
 * be private to that class, and it would not (theoretically) be visible to other objects.
 * 
 * The (tiny) problem here, however, is that for the code to be compilable, we need to provide the source code 
 * alongside the function, which makes matters difficult, and can result in abuse.
 * 
 * As such, here's an example of a list implemented in C. Note that an even better approach would be to compile
 * the private functions in a private file, which would make it possible to change the private parts.
 */

// This would be the header file.
#ifndef EXTREME_C_EXAMPLES_CHAPTER_6_3_H
#define EXTREME_C_EXAMPLES_CHAPTER_6_3_H
#include <unistd.h>
// The attribute structure with no disclosed attribute (Me: didn't know that we can delay struct field definition
// until later!)
struct list_t;
// Allocation function
struct list_t* list_malloc();
// Constructor and destructor functions
void list_init(struct list_t*);
void list_destroy(struct list_t*);
// Public behavior functions
int list_add(struct list_t*, int);
int list_get(struct list_t*, int, int*);
void list_clear(struct list_t*);
size_t list_size(struct list_t*);
void list_print(struct list_t*);

// This would be the source file.
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
// Define the alias type bool_t
typedef int bool_t;
// Define the type list_t
typedef struct {
  size_t size;
  int* items;
} list_t;

// A private behavior which checks if the list is full
bool_t __list_is_full(list_t* list) {
  return (list->size == MAX_SIZE);
}

// Another private behavior which checks the index
bool_t __check_index(list_t* list, const int index) {
  return (index >= 0 && index <= list->size);
}

// Allocates memory for a list object
list_t* list_malloc() {
  return (list_t*)malloc(sizeof(list_t));
}

// Constructor of a list object
void list_init(list_t* list) {
  list->size = 0;
  // Allocates from the heap memory
  list->items = (int*)malloc(MAX_SIZE * sizeof(int));
}

// Destructor of a list object
void list_destroy(list_t* list) {
  // Deallocates the allocated memory
  free(list->items);
}

int list_add(list_t* list, const int item) {
  // The usage of the private behavior
  if (__list_is_full(list)) {
    return -1;
  }
  list->items[list->size++] = item;
  return 0;
}

int list_get(list_t* list, const int index, int* result) {
  if (__check_index(list, index)) {
    *result = list->items[index];
    return 0;
  }
  return -1;
}

void list_clear(list_t* list) {
  list->size = 0;
}

size_t list_size(list_t* list) {
  return list->size;
}

void list_print(list_t* list) {
  printf("[");
  for (size_t i = 0; i < list->size; i++) {
    printf("%d ", list->items[i]);
  }
  printf("]\n");
}
#endif