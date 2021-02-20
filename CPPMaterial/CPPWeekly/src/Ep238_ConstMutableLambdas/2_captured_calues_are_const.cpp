/**
* The parameters defined in capture are const! You may ask, why would they be const, and not other parameters
* defined in the capture?
* 
* To understand this, we need to understand how a lambda is generated. A lambda is essentially a class, with
* the method being a CONST INLINE functional operator of that class. 
*  
For example, consider the following lambda, which is equivalent to the class shown below:
int s{}, s1{};
auto lambda = [i = 0, &s, s1](){ return i;};

class __lambda_6_17
  {
    public:
    inline  int operator()() const
    {
        return i;
    }

    private:
        int i;
        int& s;
        int s1;

    public:
        __lambda_6_17(const int& _i, int& _s, int& _s1)
            : i{ _i }
            , s{ _s }
            , s1{ _s1 }
        {}

  };

  __lambda_6_17 lambda = __lambda_6_17{ 0, s, s1 };

Notice that because the method is const, we can't change the class parameters. Notice that the only exception is
the reference parameter, which we can change in fact. Why? Because with const ref, we're not supposed to change
the reference, which we can't! Therefore, we can change the value of 's' inside the function.

Here's another important implication. Being a class, this would imply that a lambda has memory. Therefore, if
I could somehow change one parameter inside a lambda, it would have the new value in the next call. Moreover,
now we know that a lambda can be copied, hence we can say lambda1 = lambda2. Moreover, we now perfectly undersand
the impliciation of moving a lambda. It's like moving a normal class! Same can be said about assignment ops as well.
*/
