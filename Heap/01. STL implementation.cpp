/*
STL implmentation of heap
priority_queue<int>pq 
By deault it follow max heap property
priority_queue<int,vector<int>,greater<int>>pq

Operations: 

pq.push(ele) -> insert a new element in heap
pq.top() -> return top value of heap
pq.pop() -> delete top value
pq.size() -> size of heap
pq.emplace() -> insert element at the top of heap
pq.empty() -> return true if size of heap is 0 other wise returns false

---- Min heap ----
output will be in acsending order
---- Max heap ----
Output will be in descending order

Input
6
15 5 10 3 4 12
Output

Size of Priority queue is 6
Value at top of Max heap priority queue is 15
Value at top of Min heap priority queue is 3
Value in max_heap is 
15 12 10 5 4 3 
Value in max_heap is 
3 4 5 10 12 15

*/

#include<iostream>
#include<queue>
using namespace std;
int main()
{
   
    priority_queue<int>pq_max; // max heap
    priority_queue<int,vector<int>,greater<int>>pq_min; // min heap
    int n;
    cin>>n;
    while(n--)
    {
        int ele;
        cin>>ele;
        pq_max.push(ele);
        pq_min.push(ele);
    }
    cout<<"Size of Priority queue is "<<pq_max.size()<<endl;
    cout<<"Value at top of Max heap priority queue is "<<pq_max.top()<<endl;
    cout<<"Value at top of Min heap priority queue is "<<pq_min.top()<<endl;
    cout<<"Value in max_heap is \n";
    while(!pq_max.empty())
        {
            cout<<pq_max.top()<<" ";
            pq_max.pop();
        }
     cout<<"\nValue in max_heap is \n";
    while(!pq_min.empty())
        {
            cout<<pq_min.top()<<" ";
            pq_min.pop();
        }
}
