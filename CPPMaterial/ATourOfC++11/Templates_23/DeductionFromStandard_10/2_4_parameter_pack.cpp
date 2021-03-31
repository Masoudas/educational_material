/**
* Finally, regarding parameter packs, the standard states:
* "If a parameter pack appears as the last P, then the type P is matched against the type A of each remaining 
* argument of the call. Each match deduces the template arguments for the next position in the pack expansion."
* 
* The following example demonstrates the point. Notice that in this example, the templates are deduced without
* reference (and not for example int&, float&, const int&>.
* 
* Note: If we take the reference from types, z is deduced as int, and not const int. See 3_2 for the 
* understandable reason! It's very natural and simple why! But essentially, if the type is not deduced as
* const int, we'd be able to manipulate a const value as such.
*/

template<class... Types> void pack_template(Types&...) {};

void using_pack_template(int x, float& y)
{
    const int z = x;
    pack_template(x, y, z); // P = Types&..., A1 = x: deduced first member of Types... = int
                            // P = Types&..., A2 = y: deduced second member of Types... = float
                            // P = Types&..., A3 = z: deduced third member of Types... = const int
                            // calls f<int, float, const int>
}