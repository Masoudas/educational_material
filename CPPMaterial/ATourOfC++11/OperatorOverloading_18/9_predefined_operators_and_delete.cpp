/**
* Note that the definition of + does not imply the definition of += and the compiler is not going to fill it
* for us.
* 
* On the other hand, operators such as &, = and , (and not * or -> son, which do have predefined meaning,
* but only for pointers!) have predefined meaning and definition for a class. As such, they can be deleted.
*/

struct delete_predefined_ops {
	delete_predefined_ops* operator&() = delete; // Can't get a pointer to.
	delete_predefined_ops& operator=(const delete_predefined_ops&) = delete; // Can't be copy assigned.
	delete_predefined_ops& operator=(delete_predefined_ops&&) = delete; // Can't be move assigned.
};