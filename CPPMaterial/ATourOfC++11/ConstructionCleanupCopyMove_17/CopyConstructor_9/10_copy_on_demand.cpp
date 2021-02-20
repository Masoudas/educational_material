/**
* Often, we don't need to write to a copy of an object. Example is when we pass an argument as copy.
* In such situations, we can have a delayed copy. For example, we can have a bool flag saying that object
* is shared. Once the user wants to write something to that object, we set that flag to false, and perform the
* copy. This is given below as an example:
*/

struct large_object {

};

struct copy_on_demand {
	bool shared;
	large_object* original;
	large_object* copy;

	copy_on_demand(const copy_on_demand& ref) : shared{ true }, original{ref.original} {

	}

	void write_to_large_object() {
		if (shared) {
			// copy original to copy now.
			shared = false;
		}

		// work with copy object.
	}
};