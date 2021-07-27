/**
 * Of course in C, structures can be nested as well. Note that the size of complex structures is calculated in the same
 * manner as the PoD structures.
 */

typedef struct {
    int x;
    int y;
} point_t;

typedef struct {
    point_t center;
    int radius;
} circle_t;

typedef struct {
    point_t start;
    point_t end;
} line_t