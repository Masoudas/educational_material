/**
 * Just like methods, if a data member is only defined inside the source file (and C allows this, just like a
 * method,) it will be private to the structure internals. 
 * 
 * Why is this the case? Because when other files include this header file, they'd not see the private parts.
 * Granted, a user can actually use the private field (because after all it's in the memory.) However, this
 * protects the field to the extend possible.
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