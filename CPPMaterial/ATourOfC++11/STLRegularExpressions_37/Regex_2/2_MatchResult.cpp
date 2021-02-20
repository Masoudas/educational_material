/**
 * Note that all the following classes are in the regex header.
 * 
 * Results from a regular expression are gathered in a match_result object. 
 * This is the object we use to find the matches. The match_result contains 
 * one or more submatch objects, which is partially shown below:
template<class Bi> // Bi is a bidirectional iterator.
class sub_match : public pair<Bi,Bi> {
public:
    using value_type = typename iterator_traits<Bi>::value_type;
    using difference_type = typename iterator_traits<Bi>::difference_type;
    using iterator = Bi;
    using string_type = basic_string<value_type>;
    bool matched; // true if *this contains a match
    // ...
}

We shall discuss what methods sub_match brings foward below. But note that match_results is 
actually the container the gives us all sub_match classes.
*/
#include <string>
#include <regex>
#include <iostream>
//#include <match_result>

using namespace std; 
   
void first_matching() 
{ 
    //string to be searched
    string mystr = "She sells_sea shells in the sea shore"; 
   
    // regex expression for pattern to be searched 
    regex regexp("s[a-z_]+"); 
   
    // flag type for determining the matching behavior (in this case on string objects)
    smatch m; 
   
    // regex_search that searches pattern regexp in the string mystr and finds the first one.
    regex_search(mystr, m, regexp); 
    
    for (auto x : m) // contains only one match. Why?
        cout << x << endl;
}

void second_matching_example() {
//regex pat("<(.*?)>(.*?)</(.*?)>");
  //  string s = "Always look for the <b> bright </b> side of <b> death </b>";

  //  match_results<string> m;
    //if (regex_search(s, m, pat))
    //    if (m[1] == m[3]) cout << "match\n";
}

void third_matching_example() {
    regex pat("(AAAA)(BBB)?");
    string s = "AAAA AAAA";
    smatch m;
    regex_search(s, m, pat);
    cout << boolalpha;
    cout << m[0].matched << '\n'; // true: we found a match
    cout << m[1].matched << '\n'; // true: there was a first sub_match
    cout << m[2].matched << '\n'; // false: no second sub_match
    cout << m[3].matched << '\n'; // false: there couldn’t be a third sub_match for pat
}

//int main() {
//    first_matching();
//    third_matching_example();
//}