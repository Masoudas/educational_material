/**
* Selecting among N alternatives is very similar to choosing between two. Here is a type function returning its Nth 
* argument type.
* 
* The general version of select should never be used, so I didn’t define it. I chose zero-based numbering to match the 
* rest of C++ (I = 0 chooses the first type). This technique is perfectly general: such specializations can present any 
* aspect of the template arguments. We don’t really want to pick a maximum number of alternatives (here, four), but that 
* problem can be addressed using variadic templates (as we show next). The result of picking a nonexisting alternative is 
* to use the primary (general) template. For example:

Select<5,int,double ,char> x;

* In this case, that would lead to an immediate compile-time error as the general Select isn’t defined.
*/

class Nil {};

template<int I, typename T1 =Nil, typename T2 =Nil, typename T3 =Nil, typename T4 =Nil>
struct select;

template<int I, typename T1 =Nil, typename T2 =Nil, typename T3 =Nil, typename T4 =Nil>
using Select = typename select<I,T1,T2,T3,T4>::type;

// Specializations for 0-3:
template<typename T1, typename T2, typename T3, typename T4>
struct select<0,T1,T2,T3,T4> { using type = T1; }; // specialize for N==0

template<typename T1, typename T2, typename T3, typename T4>
struct select<1,T1,T2,T3,T4> { using type = T2; }; // specialize for N==1

template<typename T1, typename T2, typename T3, typename T4>
struct select<2,T1,T2,T3,T4> { using type = T3; }; // specialize for N==2

template<typename T1, typename T2, typename T3, typename T4>
struct select<3,T1,T2,T3,T4> { using type = T4; }; // specialize for N==3