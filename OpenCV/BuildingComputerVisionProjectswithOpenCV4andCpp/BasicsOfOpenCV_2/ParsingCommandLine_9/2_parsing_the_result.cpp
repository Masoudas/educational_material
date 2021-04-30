/**
 * Once the options are given, we can use two methods, namely has and get, to parse the command line options:
 * 
 *  -   T 	get<T>(const String &name, bool space_delete=true) const 
 *  -   T 	get (int index, bool space_delete=true) const
 *      Access arguments by name.
 *      Returns argument converted to selected type. If the argument is not known or can not be converted to 
 *      selected type, the error flag is set (can be checked with check, discussed next.)
 *      Note that space_delete remove spaces from the left and right of the string.
 * 
 *      Example: Suppose keys = "{N count| |}""{@image |<none>| }", then:
 *      int N = parser.get<int>("N");
 *      string img = parser.get<string>("@image")
 * 
 *  -   bool has(const String &name) const
 *      Check if field was provided in the command line. 
 * 
 * 
 */