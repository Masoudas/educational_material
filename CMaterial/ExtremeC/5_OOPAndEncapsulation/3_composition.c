/**
 * Composition in OOP implies having various other classes as part of our current class. As such, the class that
 * has other classes contained in it is called a container.
 * 
 * As long as the container object exists, the contained object must exist. But when the container object is about 
 * to get destroyed, the contained object must have been destructed first. This condition implies that the 
 * contained object is often internal and private to the container.
 * 
 * Some parts of the contained object may be still accessible through the public interface (or behavior functions) 
 * of the container class, but the lifetime of the contained object must be managed internally by the container 
 * object. If a piece of code can destruct the contained object without destructing the container object, it is a 
 * breach of the composition relationship and the relationship is no longer a composition.
 * 
 * Below, we've implemented a composition in C. We can see that car_t contains an engine_t. Note that in a composition
 * pattern, we have no choice but to allocate the contained objects on heap.
 */

#ifndef EXTREME_C_EXAMPLES_CHAPTER_7_1_CAR_H
#define EXTREME_C_EXAMPLES_CHAPTER_7_1_CAR_H
struct car_t;
// Memory allocator
struct car_t* car_new();
// Constructor
void car_ctor(struct car_t*);
// Destructor
void car_dtor(struct car_t*);
// Behavior functions
void car_start(struct car_t*);
void car_stop(struct car_t*);
double car_get_engine_temperature(struct car_t*);
#endif

#ifndef EXTREME_C_EXAMPLES_CHAPTER_7_1_ENGINE_H
#define EXTREME_C_EXAMPLES_CHAPTER_7_1_ENGINE_H
struct engine_t;
// Memory allocator
struct engine_t* engine_new();
// Constructor
void engine_ctor(struct engine_t*);
// Destructor
void engine_dtor(struct engine_t*);
// Behavior functions
void engine_turn_on(struct engine_t*);
void engine_turn_off(struct engine_t*);
double engine_get_temperature(struct engine_t*);
#endif

// Source files
#include <stdlib.h>
// Car is only able to work with the public interface of Engine
typedef struct {
  // Composition happens because of this attribute
  struct engine_t* engine;
} car_t;

// Methods

