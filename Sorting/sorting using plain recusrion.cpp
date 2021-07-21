#include<iostream>
#include<vector>
using namespace std;

void insert(vector<int>&v,int temp)
{
    if(v.size()==0 or v[v.size()-1]<=temp)
    {
         v.push_back(temp);
         return;
    }
    int x=v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(x);
    return;
       
}

void sort(vector<int>&v)
{
    if(v.size()==1)
        return;
    int temp=v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v,temp);
    return;    
}

int main() {
    vector<int>v={5,1,0,2};
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;    
    sort(v);
    for(auto x:v)
        cout<<x<<" ";

}
