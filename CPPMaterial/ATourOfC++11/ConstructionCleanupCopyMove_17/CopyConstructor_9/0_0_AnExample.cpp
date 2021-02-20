/**
* This is not Bjarne!
* 
* We know that every class by default has a copy constructor. What it does is that it essentially
* copies the memory location of this object somewhere else. Hence, it is a shallow copy.
* The copy constructor is essentially like this:
* Class(const Class& other){
*  memcpy(this, other, sizeof(Class));
* }
* Suppose we want to write an String mimicing class of our own. We'd have something like this
*/
#include <string>
#include <iostream>

class String
{
private:
    char* m_buffer;
    unsigned int m_size;
public:
    String(const char* string){
        m_size = std::strlen(string);
        m_buffer = new char[m_size + 1]; // One for null termination.

        /**
         * Note that memcopy takes the size in byte. Moreover, strlen returns the size of the string
         * not including \0. We add it here, which is important, specially for example when we stream
         * the string, so that it would know when to stop when streaming (otherwise we get a bunch of
         * weird chars until we face a null somewhere in the memory).
         * 
         * DON'T FORGET THAT memcpy does not allocate space, so you need to create the memory first!!!
         */ 
        memcpy(m_buffer, string, m_size + 1); 
        m_buffer[m_size] = '\0';  // Because pointer may not end in null character.
    };

    /**
     * The destructor deletes the memory associated with the buffer.
     * 
     * As we see below, a combination of this destructor and the default copy
     * constructor causes a problem, which we will see below.
     */
    ~String(){
        delete[] m_buffer;
    };

    /** Making this class a firend of the operator defined below!!!*/
    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

/** To make sure that we can print the string using an stream, we define the stream << operator here.
 * Then we make the String class a friend of this operator, that way, it can access it.
 * So now if we have an stream, we can say stream = stream << string. Like in a normal
 * cout we have cout << "something" << ... */
std::ostream& operator<<(std::ostream& stream, const String& string){
    stream << string.m_buffer;
    return stream;
}

/**
 * The funny thing is that this program fails upon completion of f. Why you
 * might ask? This is because by the end of the function, the destructors of the
 * objects are called. However, because we had a shallow copy, the same space
 * is occupied by first and second string. This is why when second tries to destruct,
 * it faces already deleted memory, and throws an exception!!!
 */
void printing_string(){
    String first = "Hey";

    /** As we know, here the copy constructor is called. Why not the '=' operator? See _0_1*/
    String second = first;

    std::cout << first << std::endl;    // Here, we don't call the copy constructor at all, because the
                                        // function call to operator accepts reference. See _0_1.
}


/**
 * So the copy constructor copied the content of the object memory to the new location, which entailed
 * the pointer value. However, what we really wanted was to copy the content of the pointer (not just its
 * value.)
 * 
 * Hence, we try to write a copy constructor that actually copies everything*/
class String1
{
private:
    char* m_buffer;
    unsigned int m_size;
public:
    String1(const char* string){
        m_size = std::strlen(string);
        m_buffer = new char[m_size + 1]; 
        memcpy(m_buffer, string, m_size + 1); 
        m_buffer[m_size] = '\0';
    };

    String1(const String1& other) : m_size(other.m_size){
        m_buffer = new char[m_size + 1];    
        memcpy(m_buffer, other.m_buffer, m_size + 1);   // Copies the initial object to a new memory location
    }

    ~String1(){
        delete[] m_buffer;
    };

    /** Making this class a friend of the operator defined below!!!*/
    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

/**
 * Now this code does not crash as well, because memory is independent for each.*/
void copying_our_strings(){
    String1 first = "Hey";
    String1 second = first; // This now is a deep copy.

 //   std::cout << first << std::endl;    // Here, we don't call the copy constructor at all, because the
                                        // function call to operator accepts reference. See _0_1.
}
