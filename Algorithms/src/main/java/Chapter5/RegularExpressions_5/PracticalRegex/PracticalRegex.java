package Chapter5.RegularExpressions_5;

/**
 * In normal editors, usually .* is the sign in a search bar that means search using regular expressions.
 * Normally, we want to use the match case, so that exactly what we put in the search bar is searched for.
 * 
 * For starters, we can just look for simple snippets, like abc. The matches are found. What are the matches?
 * In VS Code, these are matches that are not separated by space chars like space (\s), tab (\t) or end of line (\n).
 * Note that order of course matters in the pattern. 
 * 
 * Note also that searching for special characters that are also part of regex special characters requires caution. 
 * We cannot directly search for .[{(|^\*+?&. For these we should use in a non-raw string, or a scape backslash,
 * like \. or \\.
 * 
 * The following are the helpers we use with regex.
 * 
 * . - Any character except new line
 * \d - Any digit from 0-9.
 * \D - Not a digit.
 * \w - Word char (a-z or A-Z or 0-9 or _)
 * \W - Not a char 
 * \s - WhiteSpace (space, tab, newLine).
 * \S - not whitespace (space, tab, newLine).
 * 
 * \b - Word boundary: If one char is \w and the other is not. Start of string if first char is \w. End of String if
 *              last char is \w.
 * \B - Not a word boundary
 * ^ Beginning of string
 * $ End of string
 * 
 * [] - Matches chars set (For example [ab] means ONE Char matches a or b). There's no need to escape inside character set, because
 * why would you?! The expression knows that these are literals. If dash put at the start or end, it just
 * means dash, otherwise, a-z means range of from a to z. We can use special chars inside as well.
 * [^] - Not matches char set.
 * | - Either or
 * () Matches Group. We can use special chars inside as well. Each group has an index, starting from 1 (usually $1 or \1). We can for
 * example replace a group with what we desire, or extract that group. Example (\w\d) means a group of char. and digit (\w+) means a group
 * of at least one char. If I wanted to search for + in a group, I can write ([+]) for example. An empty paranthesis means any char. (^) means
 * beginning of string.
 * 
 * Quantifiers:
 * * Zero or more
 * + One or more
 * ? Zero or one
 * {3} Exactly Three
 * {3,5} Three to five
 * {3,} Three or more
 * 
 * 
 * \b: So with "Ha HaHa", if we write \bHa, we're searching for a word boundary, then Ha. So it will find TWO matches. The third
 * one which is second Ha in Haha is not found. \bHa\b only finds the first one. \bHa\B finds only the second one.
 * 
 * Example: [A-Za-z-] ? looks for a char from a to z, both small and capital, or a dash (the end one)!
 * 
 * Example: [^] ? If it were empty, means no char, but now that there's a negate, means every character!
 * 
 * Example: [^a-z]? Every char that is not a-z.
 * 
 * Example: [^b]at? Every pattern that is not bat!
 * 
 * Example: (!*)? This one means zero or more exclaimation marks. So what does it find? Because it says everything that has
 * zero exclaimation point, it will find every single char in the text! So be cautious!
 * 
 * Example: Is two consecutive groups possible? No. Because every group has to be terminated, that is something else
 * other than another group should be put after.
 * 
 * Example: \d{3}.\d{3}.\d{4}? Means, search for a pattern of exactly three digits, followed by a dot, then three digits followed
 * by a dot, then four digits.
 * 
 * Write a pattern that finds all names that start with Mr. Mrs. or Ms.? There could be a space after these words too, like Mr. Adams, Mr.Adams?
 * M(r|s|rs)\s?\. \w+
 * 
 * Write a pattern that will match Masoudas@hotmail.com? Well. Supposing the email address only contains small and capital letters,
 * one has to write [a-zA-Z]+@[a-zA-Z]+\.com
 * 
 * Write one that matches Masoud.As@univ-amu.fr together with previous email? 
 * Why is the previous one not matching? Because of the dot in the first part,
 * and the - in the second part, as well as the fr. So we may expand it as [a-zA-Z.]+@[a-zA-Z.]\.(com|fr).
 * 
 * Write a pattern that matches the previous one together with Masoud-123@univ-amu.net?
 * Well, we can just add a dash and 0-9 to the first part and we're done. [a-zA-Z0-9.-]+@[a-zA-Z.]\.(com|fr|net).
 * Regular expressions for matching email addresses for example can be found over the internet. They're hard to write!
 * 
 * Write a regular expression that matches these urls?
 * http://youtube.com
 * https://www.youtube.com
 * http://youtube.gov
 * https://youtube.gov
 * 
 * It would be https?://(www.)?\w+\.\w+ . Although I should specify that I prefer a [a-zA-Z0-9_-] for the domain name.
 * Now, we can use this just to get the .com or .gov (top level domain), and the domain name (which is youtube).
 * So, each group of chars, the ones that are in paranthesis, has a group number starting from 1. We can usually access a group
 * using a backslash (\1 for group 1 for example) or dollar sign ($2 for group two). WE CAN ONLY ACCESS THOSE GROUPS IN PARANTHESIS.
 * We can use this to for example replace the entire string with just domain name and top level domain using \2\3, by defining the
 * regular expression using https?://(www.)?(\w+)(\.\w+). Pleaso note that the group contains the plus sign as well.
 * 
 * 
 * The word boundary \b is kind of curious. For example AA.BB has four word boundaries (Between space and A, Between
 * A and dot, between dot and B, between B and space).
 */

