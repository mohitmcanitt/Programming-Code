#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&v,int s,int e)
{
    int i=s-1;
    int pivot=v[e]; // choosing last element as pivot
    for(int j=s;j<e;j++)
    {
        if(v[j]<pivot)
            swap(v[++i],v[j]);
    }
    swap(v[e],v[i+1]);
    return i+1;
}

void quickSort(vector<int>&v,int s,int e)
{
    if(s>=e)
        return;
    int p=partition(v,s,e);
    quickSort(v,s,p-1);
    quickSort(v,p+1,e);    
}

int main() {
    vector<int>v={4,6,2,5,7,9,1,3};
    quickSort(v,0,v.size()-1);
    for(auto x:v)
    cout<<x<<" ";
}
