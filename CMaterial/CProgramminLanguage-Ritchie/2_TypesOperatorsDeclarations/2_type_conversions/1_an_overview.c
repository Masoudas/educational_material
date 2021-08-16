/**
 * When an operator has operands of different types, they are converted to a common type according to a small 
 * number of rules. In general, the only automatic conversions are those that convert a "narrower" operand into a 
 * "wider" one without losing information, such as converting an integer into floating point in an expression like 
 * f + i . Expressions that don’t make sense, like using a float as a subscript, are disallowed. Expressions that 
 * might lose information, like assigning a longer integer type to a shorter, or a floating-point type to an 
 * integer, may draw a warning, but they are not illegal.
 * 
 */