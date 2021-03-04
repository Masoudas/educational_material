/**
* Null keys are not acceptable, and in standard implementations, methods throw exception if they're passed
* null keys.
* 
* Null values (in a Java context): We also adopt the convention that no key can be associated with the value 
* null. This convention is directly tied to our specification in the API that get() should return null for 
* keys not in the table, effectively associating the value null with every key not in the table. This 
* convention has two (intended) consequences: First, we can test whether or not the symbol table defines a 
* value associated with a given key by testing whether get() returns null. Second, we can use the operation 
* of calling put() with null as its second (value) argument to implement deletion.
* 
* Note on the C++ case: In C++, we don't check the existence of a key using the bracket operator. Instead, we
* directly use a method such as find. This is because the bracket method would create a default object for us
* if no value is associated with the key. In consequence and expression such as table[key] = value first 
* constructs a value type by default (assuming it does not exist,) then uses the copy assignment to assign to
* that value.
*/