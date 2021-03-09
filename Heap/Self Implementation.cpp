/*
INPUT
6
15 5 10 3 4 12
OUTPUT
3 12 5 15 10 4 

*/
// Implement Binary min heap
// parent of i == (i-1)/2;
// child of i == 2*i+1 and 2*i+2;

#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>&v)
{
    for(int i=1;i<v.size();i++) // start from index 1
    {
        int parent=(i-1)/2;
        int child=i;
         while(v[parent]>v[child] and parent>=0) // check with its parents value 
                                // whether new inserted element doest violate min heap property
         {
            swap(v[parent],v[child]);
            child=parent;
            parent=(child-1)/2;
         }
    }
}

int getmin(vector<int>v)
{
    if(v.size()==0)
    return -1;
    else
    return v[0];
}
bool isEmpty(vector<int>v)
{
    if(v.size()==0)
    return true;
    else 
    return false;
}

void heapify(vector<int>v,int parent)
{
    int leftChild=2*parent+1;
    int rightChild=2*parent+2;

      int index=parent; // index will store the index of (leftchild,rightchild) whose value is smaller than it
      if(leftChild<v.size() and v[parent]>leftChild)   // check only left child exist
        index=leftChild;
      if(rightChild<v.size() and v[index]>leftChild)
        index=rightChild;

     if(index==parent)
        return;
    swap(v[index],v[parent]);
    parent=index;
    heapify(v,parent);
   
    
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    while(n--)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    insert(v); // insert in binary heap
    while(!v.empty())
    {
        cout<<getmin(v)<<" ";
        swap(v[0],v[v.size()-1]);
        v.pop_back();
        heapify(v,0);
    }
}
