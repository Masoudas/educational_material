/**
* Me: As we expect, sample does not choose one element n times. It chooses n-elements from the container.
* 
*	-	SampleIterator sample(PopulationIterator first, PopulationIterator last, SampleIterator out, Distance n, URBG&& g);
* 
* Selects n elements from the sequence [first; last) (without replacement) such that each possible sample has equal 
* probability of appearance, and writes those selected elements into the output iterator out. Random numbers are generated 
* using the random number generator g.
* 
*	-	g:	the random number generator used as the source of randomness (me: note that it's a forwarding reference.)
*	-	Distance must be an integer type, and g results must be convertible to it.
* 
* 
*	
*/

#include <string>
#include <algorithm>
#include <iterator>
#include <random>
#include <iostream>

void random_sampling_stream() {
    std::string in = "hgfedcba", out;
    std::sample(in.begin(), in.end(), std::back_inserter(out),
        5, std::mt19937{ std::random_device{}() });
    std::cout << "five random letters out of " << in << " : " << out << '\n';
}