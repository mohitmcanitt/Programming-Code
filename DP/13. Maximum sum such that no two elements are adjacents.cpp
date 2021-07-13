// leetcode 198 house robber 
// leetcode 213 house robber-2 

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>v)
{
    int include=v[0];
    int exclude=0;

    for(int i=1;i<v.size();i++)
    {
        int temp1=include;
        int temp2=exclude;
        include=temp2+v[i];
        exclude=max(temp1,temp2);
    }
    return max(include,exclude);
}

int main() {
    vector<int>v{1,2,9,4,5,0,4,11,6};
    cout<<solve(v);
}
