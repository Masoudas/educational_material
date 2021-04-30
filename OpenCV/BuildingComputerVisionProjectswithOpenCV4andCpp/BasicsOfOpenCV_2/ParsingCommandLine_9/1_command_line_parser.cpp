/**
 * The command line parser found in the core/utility.hpp helps us parse command line options, and indeed define
 * simple command line options for our applications.
 * 
 * The constructor of the class is as follows:
 *      -   CommandLineParser (int argc, const char *const argv[], const String &keys)
 * 
 * The keys string (or const char*) is what we use to define the options. Each option goes into a brace, then
 * it has two |, and overall can be characterized as:
 * 
 * "{name and/or abbreviation | default value | documentation }"
 * where:
 *  -   name or abbreviation
 *      -   Could be both name and abbreviation.
 *      -   Putting an @ before it means it does not need to be explicitly stated on the command line.
 * -    Default value:
 *      -   String for strings, number for numbers, etc.
 *      -   Empty for strings means an empty string is passed. Setting it to <none> means there's no default
 *          value, and the user must pass a value.
 * 
 * The following is an example of such keys. Notice that with each "", we don't start a new string, we just allow
 * the continuation of the string to the next line:
 * 
    const char* keys =
        "{help h usage ? |      | print this message   }"
        "{@image1        |      | image1 for compare   }"
        "{@image2        |<none>| image2 for compare   }"
        "{@repeat        |1     | number               }"
        "{path           |.     | path to file         }"
        "{fps            | -1.0 | fps for output video }"
        "{N count        |100   | count of objects     }"
        "{ts timestamp   |      | use time stamp       }";

 * So, notice that image1&2 and repeat needn't be specified on the command line. Moreover, image2 must be passed 
 * a value, otherwise an exception is thrown. Other than that, typing either of h, help, usage or ? prompts a 
 * help.

# Good call (3 positional parameters: image1, image2 and repeat; N is 200, ts is true)
$ ./app -N=200 1.png 2.jpg 19 -ts

# Bad call
$ ./app -fps=aaa
ERRORS:
Parameter 'fps': can not convert: [aaa] to [double]

 * Important note: Note that the options have to be passed with an '=' sign, except for '@' options, which can
 * be passed without '='. Note that if we want to pass a string with white spaces, as always, we need to delimit
 * it with quotation.
 */