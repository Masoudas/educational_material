/**
 * Sometimes, we need a new name for an existing type. As such, we define name aliases.
 * The old way was to use typedef, the modern way is to use using:
 * using UCHAR = unsigned char;
 * 
 * Note that we can't attach unsigned or signed to an alias. Hence if I say using INT = int;
 * I can't say unsigned INT.*/