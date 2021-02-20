/**
* (Me: This section has been excerpted from the concept section in the book for more clarity and comparison)
* 
* A concept is not an arbitrary collection of properties. Most lists of properties of a type (or a set of types) 
* do not define a coherent and useful concept. To be useful as a concept, a list of requirements has to reflect 
* the needs of a set of algorithms or a set of operations of a template class.
* 
* There seem to be surprisingly few concepts that make sense. For example, algebra builds on concepts such as 
* monad, field, and ring, whereas the STL relies on concepts such as forward iterator, bidirectional iterator, and 
* random-access iterator. 
* 
* The big guy again insists that "I see a concept as a carefully crafted entity that reflects fundamental 
* properties of an application domain. Consequently, there should be only few concepts, and these can act as a 
* guideline for the design of algorithms and types. The analogy is with physical plugs and sockets; we want the 
* minimal number to simplify our lives and to keep design and construction costs down. This ideal can conflict with 
* the ideal of minimal requirements for each individual generic algorithm."
* 
* He continues "I set the bar for being a concept very high: I require generality, some stability, usability across
* many algorithms, semantic consistency, and more. In fact, many simple constraints that we’d like for template 
* arguments don’t qualify as concepts according to my criteria."
* 
* In particular, we write many templates that do not reflect general algorithms or widely applicable types. 
* Instead, they are implementation details, and their arguments only have to reflect the necessary details of a 
* template intended for a single use in a single implementation of something. We call requirements for such 
* template arguments 'constraints' or (if we must) 'ad hoc concepts'.
* 
*/