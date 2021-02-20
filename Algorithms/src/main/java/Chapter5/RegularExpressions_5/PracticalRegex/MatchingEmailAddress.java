package Chapter5.RegularExpressions_5.PracticalRegex;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Apparently, writing a pattern for checking email address is very hard. A pattern
 * that may validate some invalid addresses, but always validates valid email addresses is
 * something like this:
 * 
 * "^\S{1,}@\S{2,}\.\S{2}$"
 * This patterns says from start of string, not a white space, then at sign, then not a white space, dot,
 * then not a white space. Obviously this pattern has errors too. For example, masoudas@-hotmail.com will 
 * be accepted.
 * 
 * A dot net regex is so heavy, I'm not even going to put it here.
 * 
 * 
 */

class MatchingEmailAddress {
    public static void main(String[] args) {
        Pattern email = Pattern.compile("\\S{1,}@\\S{2,}\\.\\S{2}", Pattern.UNICODE_CASE);
        Matcher matcher = email.matcher("Masoudas@hotmail.com");

        System.out.println("A match was found: " + matcher.find());

    }
    
}
