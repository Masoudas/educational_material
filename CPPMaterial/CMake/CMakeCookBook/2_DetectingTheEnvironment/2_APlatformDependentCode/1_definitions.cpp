/**
 * As we may recall, using #define, #ifdef, #ifndef, #elseif, #endif, we can add definitions to our code
 * and remove them at will.
 * 
 * Now, here's the deal. Suppose we define a preprocessor condition for a definition like for example IS_WINDOWS. 
 * Now, to activate or disactivate it, we can define IS_WINDOWS using the #define. However, there's another
 * very interesting option. We can pass definition when we compile our code (header.) That way, without having
 * to change something inside the code, we can do it upon COMPILATION, allowing for more control over the
 * code.
 * 
 * To activate a definition, we merely have to pass the -D flag together with the preprocessor name.
 */

#ifdef IS_WINDOWS
    #include<string>
#elseif IS_LINUX
    #include<cstring>
#endif

// gcc file -DIS_LINUX -o output    # Defines IS_LINUX