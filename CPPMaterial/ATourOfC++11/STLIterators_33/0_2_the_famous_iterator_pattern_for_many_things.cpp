/**
 * There's a famous pattern which applies to many things, that I often forget, when it comes to using iterators
 * for various things. The pattern is:
 * 
 *  -   Make a begin iterator that returns the first result
 *  -   Make an end iterator, that marks the end of iteration process. Often this is an empty iterator instance
 *  -   Use a foreach structure to loop over it.
 * 
 * So what am I talking about here? For example, consider finding all instances of a regex in a string:
 * 
 * Example 1 - Regex:
 *  -   regex_iterator begin{...};  // Starting point, returns our first match, and ++ increases
 *  -   regex_iterator end{};   // End point
 *  -   for_each(being, end, [](){const match& m}{...}); // Now get a match object.
 *
 * Example 2 - istream:
 *  -   istream_iterator begin{...}; // The beginning, and what is read from the command line
 *  -   istrean_iterator end{}; // Empty case
 *  -   for_each(begin, end, [](const auto& val){ vector.push_back(val)}); 
 */
