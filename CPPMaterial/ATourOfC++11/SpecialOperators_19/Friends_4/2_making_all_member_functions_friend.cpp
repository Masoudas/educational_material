/**
* There's a way to make all functions of a class friends of another. For this end, the friend statement is declared with
* the class, where the class name proceeds the class name for clarity.
* 
* We should be cautious when declaring a friend class. Because we don't know what methods and invariants are being accessed 
* by the member class, and the friend class does not know the dynamics of our class as well.
*/

class friendee {
	friend class friend_c;

	int c;
};

class friend_c  {
	void friendee_manipulator(const friendee & e) {
		int val = e.c;
	}
};