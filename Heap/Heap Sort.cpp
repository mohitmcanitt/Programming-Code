/*
steps : for ascending order
1. convert array in max-heap array
2. swap first element with last_index;
3. shrink last_index.
4.perform heapify

*/

#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&v,int parent)
{

    int leftC=2*parent+1;
    int rightC=2*parent+2;
    int min_index=parent;
    if(leftC<v.size() and v[leftC]>v[parent])
        min_index=leftC;
    if(rightC<v.size() and v[rightC]>v[min_index])
        min_index=rightC;

    if(min_index!=parent)
    {
        swap(v[parent],v[min_index]);
        parent=min_index;
        heapify(v,parent);
    } 

}
void heapify2(vector<int>&v,int parent,int size)
{

    int leftC=2*parent+1;
    int rightC=2*parent+2;
    int min_index=parent;
    if(leftC<=size and v[leftC]>v[parent])
        min_index=leftC;
    if(rightC<=size and v[rightC]>v[min_index])
        min_index=rightC;

    if(min_index!=parent)
    {
        swap(v[parent],v[min_index]);
        parent=min_index;
        heapify2(v,parent,size);
    } 

}
void convert_into_heap_array(vector<int>&v)
{
    int Last_non_leaf_node=(v.size()-1)/2;

    for(int i=Last_non_leaf_node;i>=0;i--)
        heapify(v,i); // i will be parent and check with its childs
}

void heapSort(vector<int>&v)
{
    // perform deletion.
    // swap top value with its last value
    // dont pop elemnet from vector. Simply last index to left
    int last_index=v.size()-1;
    int size=v.size();
    int i=0;
    while(i<size)
    {
        swap(v[0],v[last_index]);
        last_index--;
        heapify2(v,0,last_index);
        i++;
    }

}

int main() {
    vector<int>v={5,41,3,2,12};
    // Make vector in heap array , let make it min heap
    convert_into_heap_array(v);
    heapSort(v);
    for(auto x:v)
    cout<<x<<" ";
}
