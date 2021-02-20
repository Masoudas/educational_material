/**
* Consider the following fact. In the global namespace, if we define a variable, then it can be used by
* every namespace. The same is sort of true for namespaces as well. Let's say I define a constant, constexpr
* or even a normal definition. This can be used globally by the namespace in which this variable is declared,
* or by possibly other namespaces.
* 
* Normally in other languages, we need to put heavyAnalyzer as a static member of a class. But in Cpp, it
* can be a part of the namespace.
*/

namespace analyzer {
	struct ImageAnalyzer {
		ImageAnalyzer(){}
		void analyze(int i) {}
	};

	ImageAnalyzer heavyAnalyzer{};
}

namespace analyzer_user {
	void analyze() {
		analyzer::heavyAnalyzer.analyze(5);
	}
}

