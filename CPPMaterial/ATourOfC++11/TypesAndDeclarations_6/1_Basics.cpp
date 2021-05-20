/**
 * As we know, not all machines comply with the same rules. Hence, for example, a char is at least 8 bit in 
 * all machines, but it may be 16 bits as well. Hence, the following:
 * char c = 64; // This is well defined in all machines.
 * char c1 = 1256;  // In some machines this may be truncated, in others it will be ok.
 * 
 * Moreover, not all pointers would be 32 bit uints as well.
 * 
 * To enforce size limits, we put them in a header file as static assertions.
 * So, imagine this is a header file. We have:
 * static_assert(sizeof(int) >= 4, "int size is not four bytes");
 * 
 * Undefined behavior however is nastier. Imagine for example:
 * const int size = 1024;
 * int a[] = new int[size];
 * a[size + size] = 10; // Undefined behavior, no exception is thrown.
 */