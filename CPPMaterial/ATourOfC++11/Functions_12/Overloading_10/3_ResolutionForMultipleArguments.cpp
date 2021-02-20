void pow_with_several_overloads(int x, int y) {

}

void pow_with_several_overloads(double x, double y) {
	// pow_with_several_overloads(2, 2.2); This call is ambiguous, because first param matches above
	// method and second one matches this method. Hence, no resolution.
}