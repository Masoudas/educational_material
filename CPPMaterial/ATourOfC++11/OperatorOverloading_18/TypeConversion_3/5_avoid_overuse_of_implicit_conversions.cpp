/**
* In general, it is wise to be sparing in the introduction of conversion operators. When used in excess, they lead to 
* ambiguities. Such ambiguities are caught by the compiler, but they can be a nuisance to resolve. Probably the best 
* idea is initially to do conversions by named functions, such as X::make_int(). If such a function becomes popular 
* enough to make explicit use inelegant, it can be replaced by a conversion operator X::operator int()
* 
* Note that if both conversion operator and constructor are defined, ambiguities may occur. For example for the
* Tiny class we defined before we have a constructor int, and a conversion to int. Consequently, if we define an operator
* such as int operator+(Tiny,Tiny), then:
void f(Tiny t, int i){
	t+i; // error, ambiguous: ‘‘operator+(t,Tiny(i))’’ or ‘‘int(t)+i’’?
}

* which is kind of far fetched, and really can't be anticipated, but is a serious problem! So, be careful in general!
*/

