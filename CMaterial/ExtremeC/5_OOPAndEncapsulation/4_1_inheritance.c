/**
 * Me: inheritance in C is about memory layout, and ensuring the base and inherited class have the same memory
 * structure. This would allow us to proclaim that one class is the child of another. Regarding behavior, we
 * need not do anything special, and we recall that a simple cast of one pointer to another suffices to work
 * with both the base and derived class. Of course, what we lack here is protected fields, but who has ever used
 * protected fields for something I wonder?!
 * 
 * Note: If the parent class has private fields in a source file or private behavior, then they needn't be in the
 * child class, and we should not repeat them of course in the child class.
 * 
 * As we have pointed out before, inheritance (or extension) is a to-be relationship, unlike composition and 
 * aggregation, which are to-have relationships. Therefore, for the preceding example, we can say that 
 * "a student is a person," which seems to be correct in the domain of educational software. Whenever a to-be 
 * relationship exists in a domain, it is probably an inheritance relationship. In the preceding example, person_t 
 * is usually called the supertype, or the base type, or simply the parent type, and student_t is usually called 
 * the child type or the inherited subtype.
 * 
 * As such, inheritance is a composition relationship, with the difference being that we don't name the composed
 * part.
 * 
 * Note that the act of casting the child class to the parent class is called upcasting.
 */

// This would be the parent class.
typedef struct {
  char first_name[32];
  char last_name[32];
  unsigned int birth_year;
} person_t;

// This would be the child class.
typedef struct {
  char first_name[32];
  char last_name[32];
  unsigned int birth_year;
  char student_number[16]; // Extra attribute
  unsigned int passed_credits; // Extra attribute
} student_t;