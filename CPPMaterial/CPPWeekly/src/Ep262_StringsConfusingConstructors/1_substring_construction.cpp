/**
* As we may recall in what the big guy discussed, we can essentially get substrings in two different manners
* from an string:
*	- Use the substring methods of class
*	- Use copy (like) constructros of the class
* 
* Note that both of these methods generate new independent strings. Now with that being said, consider the
* following, and keep in mind that this in stdc++17:
* 
* const string s1 = "Modern C++".
* 
* const string s2{"Modern C++", 3};		// The content is now "Mod"
* const string s3{s1, 3};				// The content is now "ern C++"
* 
* Why would this be the case? We shall discuss this next.
*/