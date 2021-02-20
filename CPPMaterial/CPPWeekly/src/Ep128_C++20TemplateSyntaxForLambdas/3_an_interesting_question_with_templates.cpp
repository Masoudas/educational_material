/**
* Here's a question: Why can't we generate the lambda, when its template parameter is not being used?
* I don't know, honestly!!
* 
*/
template<typename T>
void unused_template() {
	unused_template<int>();	// Ok with templated functions.
}

void templated_lambda_generator() {
	auto lambda = []<typename T>() { return 5; };

	//lambda<int>(3.3); Error!
}

//int main() {
//	templated_lambda_generator();
//}