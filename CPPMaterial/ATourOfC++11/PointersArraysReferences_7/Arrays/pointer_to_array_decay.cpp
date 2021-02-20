/** From CPP con:
* As a reminder, conversion of an array pointer to pointer of its type, which is known as decay,
* is a momentary conversion to pointer.
* 
* This is like adding an int type to a float type. Momentarily, the int type is promoted to float,
* and then added to the other float. In other words:
* double d; int i; d+=i;	--> The compiler creates double t = static_case<double>(i), and then says
*								d = d + t;
* 
* Array decay is like that. Say we have T arr[]. Then we say *arr = T{}. Then compiler says int* t = &arr[0],
* and *t = T{};
* 
* As we already know, we can't say arr = *T, because arr is a constant pointer! Another indication of
* we only have a decay.
* 
* Another indication is that for static arrays, we have sizeof(T[]) = size in char, whereas we always have
* sizeof(T*) = pointer size on the machine. Notice that alignof(T[]) = sizeof(T)! And don't ask what alignof is.
* 
*/