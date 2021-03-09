#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&v,int parent)
{

    int leftC=2*parent+1;
    int rightC=2*parent+2;
  
    int min_index=parent; // min index will store the index of their child which have max value
  
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

void convert_into_heap_array(vector<int>&v)
{
    int Last_non_leaf_node=(v.size()-1)/2;

    for(int i=Last_non_leaf_node;i>=0;i--)
        heapify(v,i); // i will be parent and check with its childs
}


int main() {
    vector<int>v={5,41,3,2,12};
    // Make vector in heap array , let make it max heap
    convert_into_heap_array(v);
   
    for(auto x:v)
    cout<<x<<" ";
}
/*
OUTPUT
41 12 3 2 5 

*/
