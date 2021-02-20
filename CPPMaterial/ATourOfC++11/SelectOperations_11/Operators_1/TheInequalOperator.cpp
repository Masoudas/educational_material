/**
 * We should not forget that when mixing signed and unsigned, the inequality operator (or any
 * other operator for that matter) promotes the signed types to unsigend types (becuase I guess 
 * the unsigned type covers a broader range). Hence, We should be REALLY cautious and avoid comparing
 * negative numbers to unsigned numbers, because the result is always true!
 */
#include <iostream>

void inequality_operator_examples(){
    std::cout << "Starting" << "The loop" << std::endl;
    for (unsigned int i = 10; i > -1; i--)
    {
        // This loop is never executed. Becuase when i is compared to -1, -1 is promoted to unsigned,
        // which is a value of 2^32 - 1. Hence, the condition is always false, and we never enter here.
        std::cout << "Not entering the loop";
    }

    std::cout << "No loop is printed";   
}