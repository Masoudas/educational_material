/**
* The proposed (Java like) interface for a symbol table resembles what is given below. In C++, however, we
* intend to use operators such as [] to get values from keys, so we integrate that into the interface as well.
* 
* Also notice the double function of the put method in the Java like structure. If we associate null with a 
* key, then if that key exists, it will be eliminated. Why? Note that the value does not determine the position
* of the key-value pair, key does. However, when the value is null, it is logical to assume that no information
* is provided for this key, hence the key is not needed, and it should be eliminated (like the word 
* 'shastashobbaghzah' has null definition in the Farsi dictionary, hence it must be eliminated.) 
* In the C++ case, however, we can't supply null for objects, unless we're dealing with pointer to objects. 
* Hence essentially, this does not happen in C++ by default! The second reason which is more important is that 
* the 'get' method in a Java like language returns nullptr if there's no associated object, which however is 
* not the case in C++ (The bracket method returns an empty constructed object for such cases)
*/

// We shall never forget that a virtual class has virtual destructor. Thus it has virtual copy and move 
// assignments, though not necessary, as a reminder of overriding the constructors.
// Don't forget that there's no such thing as virtual constructors!
template<typename Key, typename Val>
class symbol_table_java {
public:
	// Put key-value pair. Remove key if val is null (Java null)
	virtual void put(Key k, Val v) = 0;
	virtual Val get(Key k) = 0;
	virtual void contains(const Key& k) = 0;
	virtual void remove(const Key& k) = 0;
	virtual bool isEmpty() = 0;
	virtual int size() = 0;

	// virtual forward_iterator<Key> keys();
	virtual ~symbol_table_java() = 0;

	// Copy
	virtual symbol_table_java& operator=(const symbol_table_java&) = 0;

	// Move
	virtual symbol_table_java& operator=(symbol_table_java&&) = 0;
};

template<typename Key, typename Val>
class symbol_table_cpp {
public:
	// Here, we either create a new empty val, or return the coresponding val if it exists.
	virtual void put(Key, Val) = 0;	// Why not! But recall that no null key is allowed through C++ nature.
	virtual void put(Key&&, Val&&) = 0;	// For r-values.

	virtual Val& operator[](const Key&) = 0;
	
	virtual void contains(const Key&) = 0;
	virtual void remove(const Key&) = 0;
	
	virtual bool isEmpty() = 0;
	virtual int size() = 0;

	// virtual forward_iterator<Key> keys();
	virtual ~symbol_table_cpp() = 0;

	// Copy
	virtual symbol_table_cpp& operator=(const symbol_table_cpp&) = 0;

	// Move
	virtual symbol_table_cpp& operator=(symbol_table_cpp&&) = 0;
};