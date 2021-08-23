/**
 * As one might expect, the constructor, destructor, and other behaviors of an object are added to a structure
 * independently, using a macro. As such, the structure (the data members) will appear alongside behavior.
 * 
 * Also, notice that the constructor and destructor of the car object accept pointers, to allow the user to
 * create objects on stack or heap as he wishes. 
 * 
 * This is called implicit encapsulation. Note that in this method, the behavior is the same among objects, but
 * the data is not shared.
 * 
 * There are many famous open source projects that use the preceding technique to write semi-object-oriented code. 
 * One example is libcurl. If you have a look at its source code, you will see a lot of structures and functions 
 * starting with curl_. You can find the list of such functions here: https://curl.haxx.se/libcurl/c/allfuncs.html.
 */

#ifndef EXTREME_C_EXAMPLES_CHAPTER_6_1_H
#define EXTREME_C_EXAMPLES_CHAPTER_6_1_H
// This structure keeps all the attributes
// related to a car object
typedef struct {
  char name[32];
  double speed;
  double fuel;
} car_t;

// These function declarations are the behaviors of a car object
void car_construct(car_t*, const char*);
void car_destruct(car_t*);
void car_accelerate(car_t*);
void car_brake(car_t*);
void car_refuel(car_t*, double);
#endif