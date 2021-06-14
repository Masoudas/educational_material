/**
* If the type supports IEEE floating-point arithmetic (see std::numeric_limits::is_iec559):
*	-	if one operand is NaN, the result is NaN
*	-	infinity minus infinity is NaN and FE_INVALID is raised
*	-	infinity plus the negative infinity is NaN and FE_INVALID is raised
*/