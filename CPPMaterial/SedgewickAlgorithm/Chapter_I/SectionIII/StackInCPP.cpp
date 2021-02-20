/**
 * The stack is in the stack header of the STL.
 * 
 * The functions associated with stack are:
 * empty() – Returns whether the stack is empty – Time Complexity : O(1)
 * size() – Returns the size of the stack – Time Complexity : O(1)
 * top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
 * push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
 * pop() – Deletes the top most element of the stack – Time Complexity : O(1). IT DOES NOT RETURN!
 */
#include <stack> 
#include <iostream>
using namespace std; 
  
void showstack(stack<int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 
  
void calling_show_stack() 
{ 
    stack <int> s; 
    s.push(10); 
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 
  
    cout << "The stack is : "; 
    showstack(s); 
  
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 
  
    cout << "\ns.pop() : "; 
    s.pop();
    showstack(s); 
  
    return; 
} 