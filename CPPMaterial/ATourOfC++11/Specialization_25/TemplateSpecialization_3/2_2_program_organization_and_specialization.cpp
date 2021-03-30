/**
* Let's consider the implementation of complex by MSVC. Recall that we say specializations are like normal (non templated) 
* types, which is why they reduce code bloat. This then begs the question "if we define specializations right below the
* definition of a templated type in a translation unit, wouldn't several inclusion of that specialization cause the linker
* to threw an error of finding several definition of the same class?"
* 
* Now, if we consider the 'complex' file in VS std, we see that for example complex<double> is a specialization that's defined
* inside this file. Hence, it seems like everytime we write #include <complex>, the preprocessor would copy this specialization
* inside the translation unit. Consequently, in the linkeage stage, the compile would find several definitions of the literal
* complex<double> and should throw a linkeage error. But this doesn't happen. 
* 
* What's evident is that such specialization are not treated like normal types when it comes to inclusion. Hence, it safe 
* to define the specialization in the same file, like the method Microsoft uses, and there's no error. Just to further 
* stress, I checked this point with a sample mini project and it validated the hypothesis.
* 
*/