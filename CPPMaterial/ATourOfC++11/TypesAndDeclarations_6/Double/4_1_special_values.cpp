/**
* According to the standard, there are certain special values associed with floating point types:
* 
*	-	Infinity (positive and negative). see next for INFINITY. (Me: Recall that no comparison with infinity
*		or any other value must be done directly.)
*	-	The negative zero, -0.0. It compares equal to the positive zero, but is meaningful in some arithmetic 
*		operations, e.g. 1.0/0.0 == INFINITY, but 1.0/-0.0 == -INFINITY), and for some mathematical functions, 
*		e.g. sqrt(std::complex)
*	-	not-a-number (NaN), which does not compare equal with anything (including itself). Multiple bit 
*		patterns represent NaNs, see std::nan, NAN. Note that C++ takes no special notice of signalling NaNs 
*		other than detecting their support by std::numeric_limits::has_signaling_NaN, and treats all NaNs as 
*		quiet.
*/