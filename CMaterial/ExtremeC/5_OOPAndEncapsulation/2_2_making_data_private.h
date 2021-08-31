/**
 * Just like methods, if a data member is only defined inside the source file (and C allows this, just like a
 * method,) it will be private to the structure internals. 
 * 
 * Why is this the case? Because when other files include this header file, they'd not see the private parts.
 * Granted, a user can actually use the private field (because after all it's in the memory.) However, this
 * protects the field to the extend possible.
 * 
 * Note: In this method of declaring the type only, we are only allowed to keep a pointer to the type (which
 * does make sense!). This is because the type is incomplete. So, we can never create such an object on heap. 
 * Hence, for example the following line of code is wrong:
 
struct person_t;
typedef struct {
  struct person_t person; // Generates an error! 
  char student_number[16]; // Extra attribute
  unsigned int passed_credits; // Extra attribute
} student_t

 */

// Header file.
#ifndef PRIVATE_FIELD_CLASS_H
#define PRIVATE_FIELD_CLASS_H

typedef struct private_struct_t;	// This has private parts.

#endif

// Source file:
/**
 #include header.h

 typedef struct{
	 int private;
	 double very_private;
 } private_struct_t;

 */