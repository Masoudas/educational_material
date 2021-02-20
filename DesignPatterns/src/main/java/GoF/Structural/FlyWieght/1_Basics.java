/**
 * We try to make the weight of a program as much as a fly with this pattern, by
 * minimizing number of objects.
 * 
 * This pattern is mostly about memory efficiency, and it may cause some speed
 * penalty.
 * 
 * For example in a text editor, it's best to define a char object for each
 * particular character, which allows flexibility of design. The problem however
 * is that making several thousand characters for the document is costly in
 * terms of memory. FlyWeight allows object sharing among objects. The same can
 * be said about pixels in an image.
 * 
 * flyweight is a shared object that can be used in multiple contexts
 * simultaneously. The flyweight acts as an independent object in each
 * context—it's indistinguishable from an instance of the object that's not
 * shared. Flyweights cannot make assumptions about the context in which they
 * operate. To point here is that associated with a pixel for example is an
 * internal state (value) and an external state (location). The same can be said
 * about char, where the internal state is char, the external state is font,
 * location, color and so forth.
 * 
 * So now, suppose we define a limited number of chars (say 32 for arguments
 * sake), and only create one when needed, and then have a dictionary, which
 * would keep the location together with color as key, and then value would be
 * char object. This would save us a lot of memory. See 2_Example1.java.
 * Logically there is an object for every occurrence of a given character in the
 * document. Physically, however, there is one shared flyweight object per
 * character, and it appears in different contexts in the document structure.
 * Each occurrence of a particular character object refers to the same instance
 * in the shared pool of flyweight objects.
 * 
 * 
 * Example implementations in Java are BigDecimal, Integer, Float and so forth.
 * String I think is another famous example.
 * 
 */
