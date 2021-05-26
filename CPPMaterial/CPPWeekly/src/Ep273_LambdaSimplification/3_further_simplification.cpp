/**
* Apparently, as of C++23, we can actually drop the entire shebang after capture and just go straight for the
* body, assuming we don't want any input arguments:

	auto l = [ i = 0, j = i] mutable { i = std::exchange(i, j+i); return i;} # C++2b I guess
	auto l = [ i = 0, j = i] { i = std::exchange(i, j+i); return i;}
* 