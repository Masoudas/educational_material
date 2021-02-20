package Chapter5.RegularExpressions_5.PracticalRegex;

/**
 * So we will assume that we have the https:// or not. The chars used in a domain name are
 * those of \w, plus dash. For the domain, we'll have the same scenario, except we can't use
 * the dash. Now, say we wanted to get the domain name and domain as well.
 * 
 * (http[s]?://)?(www.)?([\w-]+)\.([a-zA-Z0-9]+)
 * 
 * Each URL regex has its own problems.
 * 
 * This has been suggested for Java:
 * ^(https?|ftp|file)://[-a-zA-Z0-9+&@#/%?=~_|!:,.;]*[-a-zA-Z0-9+&@#/%=~_|]
 * 
 * This would match a situation like http://a.b.c which is fine.
 */
