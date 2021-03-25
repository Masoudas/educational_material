/** 
 * Is dimension zero of an image its rows or columns? 
 * 
 * Probably we shouldn't ask this question. What we need to recall is that the last number always indicate the 
 * number of columns. For example, in a 2 * 4 image, we have two rows and four columns. Then, in a 1 * 2 * 3
 * image, we have 1 plane, two rows and one column.
 * 
 * I must avoid getting into the whole discussion of whether columns is the zeroeth dimension or not. Because in 
 * that case, if I say 'int sz[] = {1, 2, 3}', then because sz[0] = 1, one would wonder whether 0 is the number of 
 * planes or number of columns. It's the number of planes, because this is equvialent to 1 * 2 * 3.
 */