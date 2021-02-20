/**
* As Mr. Bjarne says, declaration of a static is NOT INITIALIZATION. We can't use the static unless it has been assigned
* (unlike other class params).
*
* The static parameter has to be initialized in the same scope, but outside the class body.
* If a class parameter to be initialized inside class body, it has to be declared constant!
* 
* Note that constructor is inside the class body, hence a static parameter cannot be initialized there either.
*/
#include <iostream>

using namespace std;

namespace STATIC_INIT {
	class Illegal_Static {
	private:
		//static int non_const = 10;		// This is illegal and wouldn't compile. It will need to be declared constant.

		/** This is illegal too. Initialization happens only in the constructor or outside!*/
		static int y;

	public:
		static void initializer_static() {
			y = 10;
		}

		Illegal_Static() {
			y = 10;	// Still initialized inside class body. Not allowed.
		}
	};

	class Legal_Static {
	private:
		static int inside;	// This would be initialized inside the constructor.
		static int inside_1; // This would be initialized in the scope.
		const static int inside_2 = 10;	// This however is allowed.

	public:
		static int outside;

		Legal_Static() {
		}

		static int get_inside() {
			return inside;
		}

		static int get_inside1() {
			return inside_1;
		}

		static int get_inside2() {
			return inside_2;
		}
	};
	
	int Legal_Static::outside = 10;	// This is fine too. Defined within the scope of static.
	int Legal_Static::inside = 20;
	int Legal_Static::inside_1 = 30;
}

//int main() {
//	// This would return an error, because static has not been initialized yet.
//	//	STATIC_INIT::Illegal_Static::initializer_static(); 
//
//	STATIC_INIT::Legal_Static ls{};	// Initializing the other static inside the class.
//	cout << "Properly initialized statics are: " << STATIC_INIT::Legal_Static::outside << " " << STATIC_INIT::Legal_Static::get_inside()
//		<< " " << STATIC_INIT::Legal_Static::get_inside1() << " " << STATIC_INIT::Legal_Static::get_inside2();
//
//}
