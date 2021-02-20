/**
 * list is a doubly linked list in c++. A single linked list is a forward_list
 */

#include <list>
#include <iostream>

using namespace std;
void simple_initialization(){
    list<int> ls{1, 2, 3};

    list<int>::iterator begin = ls.begin();
    list<int>::iterator end = ls.end();

    for (; begin != end; ++begin)
    {
        cout << *begin << endl;
    }


    // _List_iterator<list<int>> begin_a = ls.begin(); Why wouldn't these work?
    // _List_iterator<list<int>> end_a = ls.begin();
}

/*
* We can remove items while iterating over a list. The point is that we must make sure the iterator
* points to the next element, before we delete the current, which is why we increment as shown below.
*/
void removing_while_iterating() {
    list<int> ls{ 1, 2, 3 };

    list<int>::iterator begin = ls.begin();
    list<int>::iterator end = ls.end();

    for (; begin != end; )
    {
        cout << *begin << endl;
        list<int>::iterator ptr = begin++;
        ls.erase(ptr);
    }

    cout << "Removed all elements from list while iterating. Now size is " << ls.size();
}



