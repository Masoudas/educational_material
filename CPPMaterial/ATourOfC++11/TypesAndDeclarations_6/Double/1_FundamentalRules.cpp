/**
 * Essentially:
 * 
 * When one operand is long double, the other is promoted to that. else:
 * When one operand is double, the other is promoted to that. else:
 * When one operand is float, the other is promoted to that. 
 * 
 * Hence, float is not turned to double by default.
 */