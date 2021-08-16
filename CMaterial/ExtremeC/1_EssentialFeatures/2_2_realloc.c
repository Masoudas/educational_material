/**
 * What's the point of realloc? It's to allocate new memory, but copy the content of old memory to it. It does not
 * expand on the old memory or shrink it (which let's face it is impossible, because memory after the current address
 * may not be accessible.)
 * 
 * For a formal definition of this function, see C standard library.
 */