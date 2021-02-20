/**
 * The ternary if statements such as e1? e2:e3 can be used in constant expressions.
 *
 * If goal is assignment to a new variable, e2 and e3 must have the same type, or a common
 * base type to which they can be implicitly converted. We can also put an exception there too. 
 */
void checkPtr(int* ptr){
    int val = ptr ? *ptr : std::runtime_error{"Dude!"};
}