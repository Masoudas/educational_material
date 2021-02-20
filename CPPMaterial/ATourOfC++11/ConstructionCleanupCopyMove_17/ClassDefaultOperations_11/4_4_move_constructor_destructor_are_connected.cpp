/**
* Example 4: Partially specified invariants.
* 
* Troublesome examples that rely on invariants but only partially express them through constructors 
* or destructors are rarer but not unheard of.
* 
* If we consider the following example, we can argue that none of the given operators are in fact necessary.
* For example, the operator= assigns one class to another. However, we know that vec1 = vec2 assigns one class
* to another. Hence, we can write *this.pos = arg.pos. This is also equivalent to the default assignment operations,
* so it has to be removed.  
* 
* Moreover, the default constructor uses the magic number 9. This as we know should be avoided, but any how!
* 
* Also note that when we override one move or copy operator, the destructor should be overridden. However, the 
* point here is that we removed the assignment operator. Hence, we needn't do that. Point is that classes where only
* one default operation is overwritten are under suspesion, and we should take a second before doing so.
* In fact, the class in its original form had only removed the move operations. Was it what we intended? Probably
* not.
* 
*/
#include <vector>
using namespace std;
class Tic_tac_toe {
public:
	Tic_tac_toe() : pos(9) {} // always 9 positions
	Tic_tac_toe& operator=(const Tic_tac_toe& arg)
	{
		for (int i = 0; i < 9; ++i)
			pos.at(i) = arg.pos.at(i);
		return *this;
	}
	// ... other operations ...
	enum State { empty, nought, cross };
private:
	vector<State> pos;
};