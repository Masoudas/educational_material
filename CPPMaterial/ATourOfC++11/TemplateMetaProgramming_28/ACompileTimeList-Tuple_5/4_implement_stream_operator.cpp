/**
* As such, the stream operator can be implemented using four overloads, as shown below:

template<typename T1, typename T2, typename T3, typename T4>
ostream& operator<<(ostream& o, const Tuple<T1, T2, T3, T4>& t){ o << t.x; }

template<typename T1, typename T2, typename T3>
ostream& operator<<(ostream& o, const Tuple<T1, T2, T3>& t){ o << t.x; }

template<typename T1, typename T2>
ostream& operator<<(ostream& o, const Tuple<T1, T2>& t){ o << t.x; }

template<typename T1>
ostream& operator<<(ostream& o, const Tuple<T1>& t){ o << t.x; }

template<>
ostream& operator<<(ostream& o, const Tuple<>& t){ }

* Me: A more interesting solution would be to select for example from the 
*/