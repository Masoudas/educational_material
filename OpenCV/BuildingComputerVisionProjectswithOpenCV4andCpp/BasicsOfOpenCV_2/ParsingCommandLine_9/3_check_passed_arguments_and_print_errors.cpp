/**
 * If the parser has failed, due to lack of parameters provided or that it's not possible to convert the params,
 * we can throw an error on the command line and then print the error messages as well, using the check and
 * printErrors command:
 * 
 *  -   void check()
 *      Check for parsing errors. Returns false if error occurred while accessing the parameters (bad conversion, 
 *      missing arguments, etc.). Call printErrors to print error messages list. 
 * 
 *  -   void cv::CommandLineParser::printErrors() const   
 *      Print list of errors occurred. 
 * 
 * Interestingly enough, normally people put this bit at the end of the code for parsing the command line params,
 * after having read all the params using get. I think this is because we can't see if an error has occured unless
 * we actually read the parameters.
 * 
 * Finally, we want to terminate the application after printing the errors, usually with a return statement.
 */