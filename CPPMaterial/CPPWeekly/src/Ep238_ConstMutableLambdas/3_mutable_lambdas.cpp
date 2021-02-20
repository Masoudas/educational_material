/**
* So, what is the solution to the problem of wanting to change a parameter inside the lambda?
* So if this were a normal, we'd introduce the keyword mutable behind the class invariants. We can
* essentially do the same thing here too.
* 
* So now, a lambda would be a class with a inline functional operator. In other words, the method is no
* longer CONST.

int s{}, s1{};
auto lambda = [i = 0, &s, s1](){ return i;};

  class __lambda_4_17
  {
    public:
    inline int operator()()
    {
        return i++;
    }

    private:
        int i;
        int& s;
        int s1;

    public:
        __lambda_4_17(const int& _i, int& _s, int& _s1)
            : i{ _i }
            , s{ _s }
            , s1{ _s1 }
        {}

  };

  __lambda_4_17 lambda = __lambda_4_17{ 0, s, s1 };
}

*/