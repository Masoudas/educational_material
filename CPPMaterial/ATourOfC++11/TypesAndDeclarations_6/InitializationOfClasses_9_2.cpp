/**
 * All of this is Me, and not Bjarne:
 * 
 * At this point, we may want to consider all methods of initializing a class in c++.
 * Entity ent1;                //Uses the default constructor, so x=0 and y=0
 * Entity ent2();              
 * Entity ent3(1, 2);          //Made constructor, so x=1 and y=2
 * Entity ent4 = Entity();     //Default constructor, so x=0 and y=0
 * Entity ent5 = Entity(2, 3); //Made constructor, so x=2 and y=3
 * Entity ent6 {};
 * Entity ent7 {6, 7};
 * 
 * As Bjarne said, an empty initialization if done on user defined types uses default constructor.
 * Hence, ent1 is initialized to default.  ent2 is treated as function definition (Yauza), hence must
 * be avoided. ent3 to ent5 are all functional initialization. ent6 is initialized with default constructor.
 * ent7 is still mysterious to me. Does it use the two parameter constructor, or the default, and sets the 
 * public fields using the values in the bracket? It appears to be the first case, because with the vector
 * class we have a constructor:
 * vector( std::initializer_list<T> init, const Allocator& alloc = Allocator() )
 * and because the second parameter is optional, I assume the constructor vector<double> v{1,1} calls this
 * constrcutor.
 * 
 * Going back to ent2, because this is interpreted as function (apparently the rule is that everything
 * that can be interpreted as function is interpreted as one), the solution is of course to use {} from c++11.
 * However, in older versions, we could have put another paranthesis, like Entity ent2(()).
 * 
 * Note also that even something like this is interpreted as function prototype:
 * std::vector<T> v(std::istream_iterator<T>(ifs), std::istream_iterator<T>()),
 * where we clearly intend to initialize the class.
 * 
 * Hence, best to avoid the functional initialization in all cases!
 */

class Entity {
public:
    int x, y;

    Entity() : x(0), y(0) { }
    Entity(int x, int y) : x(x), y(y) { }
};
 