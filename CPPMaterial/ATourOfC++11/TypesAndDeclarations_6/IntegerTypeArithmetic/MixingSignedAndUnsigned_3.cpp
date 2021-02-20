/**
When mixing an unsigned and signed integral variable (starting from int), the result is promoted to unsigned. Why is
this the case? Because supposedly the unsigned has a larger range than the signed variable. Note that the bytes
are not changed, only their interpretation.

int x = -10;
unsigned int y = 5;

cout << x + y << endl;

Now in this expression, we're mixing an int with an unsigned int. Hence, int is promoted to unsigned (2^w - x). 
Hence, the result is a gigantic number.

Note that the same situation happens with literals.

cout << -10 + 10u << endl; Here, 10 is promoted to uint. However, the result still fits a uint, so we're good.
cout << -10 + 9u << endl; Here, the result is a gigantic positive number, because we're assigning a negative value to an unsigned literal.

What would be printed here:

unsigned long int x = 0;
--x; ++x; std::cout << x;

Well, first x becomes 2^(w+1) - 1, where w is the size of long int. Then we add 1 and it becomes 2^(w+1),
then it is implicity casted to long int, resulting in ZERO!!!
*/
