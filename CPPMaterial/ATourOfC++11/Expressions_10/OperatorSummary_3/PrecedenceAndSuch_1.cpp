/**
 * As we always know, / and * has precedence over + and -.
 * 
 * Except for bitwise and assignment operators that are right associative, other operators are
 * left associative. For example, a=b=c means a=(b=c), whereas a + b + c means (a+b)+c.
 * 
 * Take a look at this: a=b<c?d=e:f=g. Obviously it means a=((b<c)?(d=e):(f=g))
 */