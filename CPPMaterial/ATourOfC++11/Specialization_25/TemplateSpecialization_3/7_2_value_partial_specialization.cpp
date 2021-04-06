/** Still me:
* This notion is quite interesting when it gets to trying to specialize with respect to a value template. But then again,
* the idea is the same. We just define as many templates as we require inside our specializations. We should just remember
* to keep the order of templates. That is, if the first template is the value template, we must define the first template
* in specialization as value.
*/

template<int N, typename T1, typename T2>
struct S{};

template<typename T1, typename T2>
struct S<0, T1, T2>{};

template<int N, typename T2>
struct S<N, int, T2> {};