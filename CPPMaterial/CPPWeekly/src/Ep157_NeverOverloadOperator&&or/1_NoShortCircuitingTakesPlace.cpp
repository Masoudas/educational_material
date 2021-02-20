/**
* In short, if we consider the following example, we see that to execute the short circut operation,
* we need to go so far as executing the || operator inside the operator overloading function. Therefore,
* we should not overload the short circut logic or the comma operator.
* 
* In short, always use the normal operators.
*/
struct logic {
	operator bool() { return true; }

	friend logic& operator||(const logic& rhs, const logic& lhs){
		return rhs || lhs;	// We have to come here to this expression every time.
	}
};

void using_short_circuit_logic() {
	logic{} || logic{};	// Unfortunately, this does not stop at creating the first logic instance and terminate
						// operation. It rather creates the second one as well, as opposed to a normal short
						// circuit operator. 
}