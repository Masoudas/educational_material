/**
* Because of the side-effects involved, built-in increment and decrement operators must be used with care to avoid 
* undefined behavior due to violations of sequencing rules.
* 
* Because a temporary copy of the object is constructed during post-increment and post-decrement, pre-increment or 
* pre-decrement operators are usually more efficient in contexts where the returned value is not used.
*/