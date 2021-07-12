#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>v,int size,int target)
{
    if(target==0)
        return true;
    if(target<0)
        return false;
    if(size==0)
    {
        if(target==0)
            return true;
        else
            return false;    

    }    

    return solve(v,size-1,target) or solve(v,size-1,target-v[size]);
}


int main() {
    vector<int>v={3, 34, 4, 12, 5, 2};
    int size=v.size()-1;
    int sum=9;
    if(solve(v,size,sum))
        cout<<"Present ";
     else   
     cout<<"Not Present";   
}
