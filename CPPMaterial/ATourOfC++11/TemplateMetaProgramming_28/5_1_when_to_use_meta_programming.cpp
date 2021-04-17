/** This is taken from a later discussion by the big guy
* Using the control structures described in this chapter, we can compute absolutely everything at compile time (translation 
* limits permitting).  The question remains: Why would you want to? We should use these techniques if and when they yield 
* cleaner, better-performing, and easier-to-maintain code than alternative techniques. The most obvious constraint on 
* metaprogramming is that code depending on complicated uses of templates can be hard to read and very hard to debug. 
* Non-trivial uses of templates can also impact compile times. If you have a hard time understanding what is going on in 
* code requiring complicated patterns of instantiation, so might the compiler. Worse still, so may the programmer who gets 
* to maintain your code
* 
* Template metaprogramming attracts clever people: 
*	-	Partly, that’s because metaprogramming allows us to express things that simply can’t be done at the same level of 
*		type safety and run-time performance. When the improvements are significant and the code maintainable, these are 
*		good – sometimes even compelling – reasons.
*	-	Partly, that’s because metaprogramming allows us to show off our cleverness. Obviously, that is to be avoided!
* 
* How would you know that you have gone too far with metaprogramming? One warning sign that I use is an urge to use 
* macros to hide "details" that have become too ugly to deal with directly. Consider:

#define IF(c,x,y) typename std::conditional<(c),x,y>::type

* Is this going too far? It allows us to write:

IF(cond,Cube,Square) z;

* rather than

typename std::conditional<(cond),Cube,Square>::type z;

* I have biased the question by using the very short name IF and the long form std::conditional. Similarly, a more complex 
* condition would almost equalize the number of characters used. The fundamental difference is that I have to write 
* typename and ::type to use the standard’s terminology. That exposes the template implementation technique. I would like 
* to hide that, and the macro does. However, if many people need to collaborate and programs get large, a bit of verbosity 
* is preferable to a divergence of notations.
* 
* Another serious argument against the IF macro is that its name is misleading: conditional is not a "drop-in replacement" 
* for a conventional if. That ::type represents a significant difference: conditional selects between types; IT DOES NOT
* DIRECTLY ALTER THE CONTROL FLOW. Sometimes it is used to select a function and thus represent a branch in a computation; 
* sometimes it is not. The IF macro hides an essential aspect of its function. Similar objections can be leveled at many 
* other "sensible" macros: they are named for some programmer’s particular idea of their use, rather than reflecting 
* fundamental functionality.
*/