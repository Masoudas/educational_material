/**
* Note that as opposed to functions whose types can be deduced, class types cannot be deduced.
* Hence, we can't say X<> x{} for a class. This is due to the versatility and flexibility the 
* class constructor provides for us. Especially imagine if we say X<> x{X<float>{}}. Then, is the
* type float or something else?
*/