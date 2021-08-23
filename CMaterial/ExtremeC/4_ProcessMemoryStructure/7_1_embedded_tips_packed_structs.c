/**
 * One tip when working with embedded environments is to use packed structures. These structures discard memory
 * alignment which helps save memory, but at the same time, they slow down the code, because memory alignment
 * is out of the picture.
 * 
 * As we may recall, packed structures are made using the __packed__ decorator.
 */

struct __attribute__((__packed__)) my_struct{
	
};