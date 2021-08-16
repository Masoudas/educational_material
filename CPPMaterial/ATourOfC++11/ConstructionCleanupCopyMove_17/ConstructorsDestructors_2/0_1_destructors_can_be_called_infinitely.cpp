/**
 * As far as I've seen, the destructors of a class can be called infinitely many times. What they do is essentially
 * nullify the content of a class, if such an operation makes sense.
 * 
 * It's however the pointer dellocation process (with free or delete) that can't be repeated.
 */