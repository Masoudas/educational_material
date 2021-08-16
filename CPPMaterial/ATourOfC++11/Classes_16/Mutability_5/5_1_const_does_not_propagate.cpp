/**
* From "High Performance C++ - Packt publishing":
* 
* Note that const does not propage. Hence, even though declaring a class object members const, the members themselves are 
* subject to change. This is similar to nested classes of a class.
* 
* A very delicate note from me: So note that this is in the case where for example the content of the pointer is not allocated
* in the same place as the class. That is' it's allocated on heap rather than stack. For example, below we see that stack_ptr
* content can't be modified, because its allocated memory belong to the same place as the class, hence it has the same constness!
*/

struct data {
	char* arr = new char[2]{};
	char stack_ptr[2] = {};

	void set_char(char c) const {
		arr[0] = c;		// Fine!
		// heap_ptr[0] = 'c'; Error! This one can't be changed. Stack pointer is now constant.
	}

};

void using_const_data() {
	const data d_{};
	//d_.arr = new char[5]{}; Error! Attempting to change const pointer
	
	d_.arr[0] = 'c';
	//d_.stack_ptr[1] = 'c';	// Error! Can't change constant heap memory!
}
