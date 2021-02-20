/** This is me:
* As we may recall, a pointer is not a literal type, hence it cannot be a constexpr. However, we can define
* pointers that are addresses of constexpr objects.
* 
* 
* This is my speculation: in order for us to define a constexpr pointer, the object has to have been defined 
* before hand, so that we can keep its address as constexpr pointer. If this is the case, then the object is
* constant. Therefore, a constexpr point needs to point a constant object. For this reason, constexpr always
* goes has to come with a const, saying consexpr T const*, where const makes the type T constant. The constexpr
* makes the pointer constant, not the type
* 
* If this is the case, then does T constexpr* mean anything? Well, you look at this and you expect this
* would read as pointer to constant T. But it's not! It's actually read as constexpr T*, or indeed
* T *const! This apparently is a quirk of VS!
* 
* 
*/

constexpr int x = 10;
constexpr int const* w = &x;

int q = 10;
constexpr int* w1 = &q;

class constexpr_c {
public:
	constexpr constexpr_c(){}
	constexpr_c(const constexpr_c&) = delete;
	constexpr_c(constexpr_c&&) = delete;

};


constexpr constexpr_c c{};
constexpr constexpr_c const* c1 = &c;

