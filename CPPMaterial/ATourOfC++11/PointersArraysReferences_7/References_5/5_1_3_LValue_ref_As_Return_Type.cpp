/**
 * Now, because a reference is an lvalue, if returned by a function, it can be assigned to, meaning
 * the function can be both on the left and right hand side of an argument. (left hand side due to
 * dereferencing, and right hand side for being an lvalue).
 *
 * This may at first seem bizzare, but we do it all the time. For example, if we override the [] operator
 * (think of it as a function!), we want to be able to assign to the result. Hence, it's usually a good idea 
 * to return &T, as does the operator[] function of the Map class of STL. An implementation is given below.
 * Hence we can say map[key] = val; or ++map[key];
 *
 */
#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

 template<class K, class V>
 class Map {//a simple map class
 public:
     V& operator[](const K& v); //return the value corresponding to the key v
     pair<K,V>*begin() { return &elem[0]; }
     pair<K,V>*end() { return &elem[0] + elem.size(); }

 private:
     vector<pair<K,V>> elem; //{key,value} pairs
 };

/** 
* It passes the key argument, k, by reference because it might be of a type that is expensive to copy. Similarly, 
* It return the value by reference because it too might be of a type that is expensive to copy.
*/
template<class K, class V>V& Map<K,V>::operator[](const K& k){
    for (auto& x : elem)
        if (k == x.first)
            return x.second;
      
    elem.push_back({k,V{}});         //add pair at end 
    return elem.back().second; //return the (default) value of the new element
}

/**
* Here's a cool use of this map. We want to count the number of appearance of each individual
* substring in a string. */
void string_counter_using_map(){
    map<string, int> map;
   
    // for (string s; cin >> s ; ) { ++map[s];} This version suggested by Bjarne does not work.
    // Perhaps the s.clear() is unnecessary as well.
    for (string s; getline(cin, s, '\n') && s.length() != 0; s.clear()) { ++map[s]; }

    // Cool line of code. Apparently cin reads one word from the input stream and
    // puts it in s. the rest is clear. We add to key corresponding to stream.

    for (const auto x : map){
        cout << x.first << ": " << x.second << '\n';
    }
       
}
