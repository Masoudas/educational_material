/**
* A prvalue of type float can be converted to a prvalue of type double. The value does not change.
* 
* ME: for example, when adding a float to a double, this happens.
*/

void promotion_to_double() {
	auto r = 10.2f + 10.;	// 10. is a double literal, added to a float. Float is promoted.
}