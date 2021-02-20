/**
* Here, we discuss how to supply a comparator method to form a pq for a custom type.
*
* First point, note that priority queue has the following type definition and constructor:
* template <typename T, typename container, typename comp>
* priority_queue{
*	priority_queue(const comp&){}
*	...
* }
*
* The point here is that the constructor accepts a comparater of the type defined by template. Moreover, it uses
* the functional interface of that type with arguments (const S& lhs, const S& rhs) to do the comparison. The reason
* why some constructors accept const ref is for us to pass a comparater if we've already made it, otherwise pq
* creates one for us. My point is that we can't simply define a lambda and then pass it to pq, because the
* constructor is not templated by itself, it uses the template of the pq
* (Note: If we want to do so, we need to use decltype, and then pass the lambda, but this is crazy).
*
* The point of confusion for me was this:
* My instinct here is to pass a lambda, or for example a member function of the type (like less) for comparison.
* The problem however this member is not a type, and based on the definition of priority_queue, my comparator
* needs to be of the type defined by the template. So basically I can't pass less here, because less is not a
* type, but rather a member function (but pq explicitly asks me to pass the comparator as a type).
*
* Which brings us to the next point. If the comparator should be a type (a class), which class then should it be?
* Note that in the end, pq uses the functional interface of that type for comparison
* There are three options here:
*	1- Use the type's functional interface: This may be fine, but for example in the following we see that
*		the type S has no default constructors. Hence, we need to create a separate instance of it and pass it
*		inside. Another problem here would be that functional operator can only be designated to one comparison
*		(only less for example), and we wouldn't be able to use it for other things).
*	2- Create a type for comparison: This may be fine too, but note that we have to declare in our API to use
		this type for comparison. Plus, we'd need a separate type for less, equal, less_equal, etc
*	3- Use std::less: This at first seems odd. But remember, std::less only uses < of the type to compare. And
*		here lies the most important point. We thus only need to overload the '<', '>', ... operators of the class
*		in order to have our comparator method. So, this would be the superior method! I know that at this point,
*		this solution may seem trivial, but for a second, I was consfused!
*
* Finally, note that we can pass a function pointer as type (like I do in passing_lambda_to_pq),
* but we have to agree that using the less functional interface is a lot less painful.
*/
#include <queue>

struct S {
	int n;
	S(int n) : n { n } {}

	bool operator()(const S& lhs, const S& rhs) {
		return lhs.n > rhs.n;
	}

	bool less(const S& lhs, const S& rhs) { return lhs.n < rhs.n; }

	friend bool operator<(const S& lhs, const S& rhs) {
		return lhs.n < rhs.n;
	}
};

void passing_lambda_to_pq() {
	auto comp = [](const S&, const S&) {return true; };
	
	// std::priority_queue<S> pq{comp};	We can't simply pass this lambda, because there's no templated
										// type for it 

	std::priority_queue<S, std::vector<S>, decltype(comp)> pq{ comp };
}


void using_type_as_comparator(){
	// std::priority_queue<S, std::vector<S>, S> pq{};	// Still throws as an error, because pq will
														// try to create an instance of S, but because it has
														// no default ctr, throws an error.

	std::priority_queue<S, std::vector<S>, S> pq{ S{1} };	// Fine, but ver, very weird! Plus, only maxPQ 
															// is possible!
}

void best_approach() {
	std::priority_queue<S> pq{ };	// Easy peasy! Creates a maxPQ using std::less and the < operator of S.
}