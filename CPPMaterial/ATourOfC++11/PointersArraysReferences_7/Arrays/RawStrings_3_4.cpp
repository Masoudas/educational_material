/**
 * To avoid using backslashes, quotation, brackets with backslash, we use raw strings.
 * 
 * The raw string notation is R"(ccc)", where the paranthesis are necessary.
 * 
 * R"(\This[])"; \This[]
 * 
 * So the paranthesis are necessary. So how do we put paranthesis in the beginning?
 * 
 * Raw strings are mostly used with regular expressions (like R"(\w\\w)) two words spaced by char).
 * other than, little use.
 */ 