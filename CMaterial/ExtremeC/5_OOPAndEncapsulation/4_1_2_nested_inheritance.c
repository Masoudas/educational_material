/**
 * It's possible to use nested structures for inheritance. That way, we ensure that a change in the parent struct
 * does reflect in the child class. But this is not straightforward. Consider:

struct person_t;
typedef struct {
  struct person_t person; // Generates an error! 
  char student_number[16]; // Extra attribute
  unsigned int passed_credits; // Extra attribute
} student_t;

 * Why does it generate an error for person? Because we can't create an instance of incomplete types. So, we 
 * need to have the actual definition of the class here. But how do we do that? Two ways come to mind:
 * 
 * 	-	We provide the implementation here (Which defeats the purpose of nesting!)
 * 	-	Define a private header for person to bring its definition where ever needed
 * 	-	Make it so that child has only access to public interface of the nested class.
 * 
 * We shall explore this further.
 */