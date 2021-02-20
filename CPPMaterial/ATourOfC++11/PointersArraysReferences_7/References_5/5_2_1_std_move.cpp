/**
* The standard library provide us with std::move(T), which is a short hand for static_cast<T&&>().
* Mr. Bjarne believes it should have been called rval(), but anyways ...
* 
* Here's swap, implemented using std::move().
* 
* Question: How does std::move itself avoids a copy? Using a reference. I think this is the implementation:
*  void __CLR_OR_THIS_CALL move(basic_ios& _Right) {
        if (this != _STD addressof(_Right)) {
            _Mystrbuf = nullptr;
            _Tiestr   = nullptr;
            this->swap(_Right);
        }
    }
*/
using namespace std;

template<typename T>
void swap_using_std_move(T& a, T& b) {
	T temp = move(a);
	a = move(b);
	b = move(temp);
}
