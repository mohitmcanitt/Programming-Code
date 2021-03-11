/* 
 Lists are sequence containers that allow non-contiguous memory allocation.
 As compared to vector, list has slow traversal, 
 but once a position has been found, insertion and deletion are quick. 
 Normally, when we say a List, we talk about doubly linked list. 
 For implementing a singly linked list, we use forward list.

Operations:

front() – Returns the value of the first element in the list.
back() – Returns the value of the last element in the list .
push_front(g) – Adds a new element ‘g’ at the beginning of the list .
push_back(g) – Adds a new element ‘g’ at the end of the list.
pop_front() – Removes the first element of the list, and reduces size of the list by 1.
pop_back() – Removes the last element of the list, and reduces size of the list by 1.
empty() – Returns whether the list is empty(1) or not(0).
insert() – Inserts new elements in the list before the element at a specified position.
erase() – Removes a single element or a range of elements from the list.
assign() – Assigns new elements to list by replacing current elements and resizes the list.
remove() – Removes all the elements from the list, which are equal to given element.
list::remove_if() in C++ STL– Used to remove all the values from the list that correspond true to the predicate or condition given as parameter to the function.
reverse() – Reverses the list.
size() – Returns the number of elements in the list.
list resize()function in C++ STL– Used to resize a list container.
sort() – Sorts the list in increasing order.
list max_size() function in C++ STL– Returns the maximum number of elements a list container can hold.
list unique() in C++ STL– Removes all duplicate consecutive elements from the list.
list merge() function in C++ STL– Merges two sorted lists into one

*/


#include <iostream>
#include<list>
using namespace std;
int main() {
     list<int>l;
     int n;
     cin>>n;
     while(n--)
     {
        int ele;
        cin>>ele;
        l.push_back(ele);
     }

     cout<<l.begin();

        l.sort();
    for(auto x:l)
        cout<<x<<" ";
}
