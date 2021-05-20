/**
* Note that the standard implicates that:
*							1 == sizeof(char) <= sizeof(short) <= ...
* The emphasis here is that sizeof always returns 1 for char. Therefore, whatever is measured with sizeof is
* measured in terms of char, and NOT byte. Therefore, on some platform where int is 4, and char is actually 
* 2 bytes, an int would be 64 bits.
*/