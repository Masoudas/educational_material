/**
* Recently, when I was working with Qt, I ran into the following case, where I defined a ui pointer inside the
* class, but forgot to initalize it.
* 
* Now, when the class memory map is layed out, the pointer would get some random value. Then, when checking
* whether it was null or not, it would say that it was null, but I had forgotten to assign to it :D
* 
* Point is, always make sure that every member of the class is initialized.
*/

struct UI{};

struct window {
	window(){}	// Forgot to initialize ui field to nullptr

	void making_the_ui() {
		if (!ui) {	// OOPS! field has non null value, this loop is never called!
			ui = new UI;	
		}
		//ui.exec() Crash! accessing unallocated memory!
	}

	UI* ui;
};